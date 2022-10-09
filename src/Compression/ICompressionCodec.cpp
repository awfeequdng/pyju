#include "ICompressionCodec.h"

#include <cassert>
#include <base/unaligned.h>
#include <Common/Exception.h>

namespace DB
{

namespace ErrorCodes
{
    extern const int CANNOT_DECOMPRESS;
    extern const int CORRUPTED_DATA;
    extern const int LOGICAL_ERROR;
}


void ICompressionCodec::setCodecDescription(const String & codec_name, const Strings & arguments)
{
    String codec = "CODEC";

    if (!codec_name.empty()) {
        codec = codec_name;
    }

    codec_desc = codec;
    full_codec_desc = arguments;
}


Strings ICompressionCodec::getFullCodecDesc() const
{
    if (full_codec_desc.size() == 0)
        throw Exception("Codec description is not prepared", ErrorCodes::LOGICAL_ERROR);

    return full_codec_desc;
}


String ICompressionCodec::getCodecDesc() const
{
    return codec_desc;
}

UInt64 ICompressionCodec::getHash() const
{
    SipHash hash;
    updateHash(hash);
    return hash.get64();
}

UInt32 ICompressionCodec::compress(const char * source, UInt32 source_size, char * dest) const
{
    assert(source != nullptr && dest != nullptr);

    dest[0] = getMethodByte();
    UInt8 header_size = getHeaderSize();
    /// Write data from header_size
    UInt32 compressed_bytes_written = doCompressData(source, source_size, &dest[header_size]);
    unalignedStore<UInt32>(&dest[1], compressed_bytes_written + header_size);
    unalignedStore<UInt32>(&dest[5], source_size);
    return header_size + compressed_bytes_written;
}


UInt32 ICompressionCodec::decompress(const char * source, UInt32 source_size, char * dest) const
{
    assert(source != nullptr && dest != nullptr);

    UInt8 header_size = getHeaderSize();
    if (source_size < header_size)
        throw Exception(ErrorCodes::CORRUPTED_DATA, "Can't decompress data: the compressed data size ({}, this should include header size) is less than the header size ({})", source_size, static_cast<size_t>(header_size));

    uint8_t our_method = getMethodByte();
    uint8_t method = source[0];
    if (method != our_method)
        throw Exception(ErrorCodes::CANNOT_DECOMPRESS, "Can't decompress data with codec byte {} using codec with byte {}", method, our_method);

    UInt32 decompressed_size = readDecompressedBlockSize(source);
    doDecompressData(&source[header_size], source_size - header_size, dest, decompressed_size);

    return decompressed_size;
}

UInt32 ICompressionCodec::readCompressedBlockSize(const char * source)
{
    UInt32 compressed_block_size = unalignedLoad<UInt32>(&source[1]);
    if (compressed_block_size == 0)
        throw Exception(ErrorCodes::CORRUPTED_DATA, "Can't decompress data: header is corrupt with compressed block size 0");
    return compressed_block_size;
}


UInt32 ICompressionCodec::readDecompressedBlockSize(const char * source)
{
    UInt32 decompressed_block_size = unalignedLoad<UInt32>(&source[5]);
    if (decompressed_block_size == 0)
        throw Exception(ErrorCodes::CORRUPTED_DATA, "Can't decompress data: header is corrupt with decompressed block size 0");
    return decompressed_block_size;
}


uint8_t ICompressionCodec::readMethod(const char * source)
{
    return static_cast<uint8_t>(source[0]);
}

}
