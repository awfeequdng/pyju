#include "config_core.h"

#include <Compression/CompressionFactory.h>
#include <Poco/String.h>
#include <IO/ReadBuffer.h>
#include <Compression/CompressionCodecMultiple.h>
#include <Compression/CompressionCodecNone.h>
#include <IO/WriteHelpers.h>

#include <boost/algorithm/string/join.hpp>
#include <unordered_map>

namespace DB
{

namespace ErrorCodes
{
    extern const int LOGICAL_ERROR;
    extern const int UNKNOWN_CODEC;
    extern const int UNEXPECTED_AST_STRUCTURE;
    extern const int DATA_TYPE_CANNOT_HAVE_ARGUMENTS;
}

CompressionCodecPtr CompressionCodecFactory::getDefaultCodec() const
{
    return default_codec;
}


CompressionCodecPtr CompressionCodecFactory::get(const String & family_name, std::optional<int> level) const
{
    std::unordered_map<String, Strings> parameters;
    if (level)
    {
        auto level_literal = static_cast<UInt64>(*level);
        Strings args;
        args.push_back(std::to_string(level_literal));
        parameters[family_name] = args;
    }
    else
    {
        parameters[family_name] = {};
    }
    return get(parameters, {});
}


CompressionCodecPtr CompressionCodecFactory::get(
    const std::unordered_map<String, Strings> & parameters, const String & data_type, CompressionCodecPtr current_default, bool only_generic) const
{
    if (current_default == nullptr)
        current_default = default_codec;

    Codecs codecs;
    codecs.reserve(parameters.size());
    for (const auto & entity : parameters)
    {
        String codec_family_name = entity.first;
        Strings codec_arguments = entity.second;
        if (codec_family_name.empty())
            throw Exception("empty family name for compression codec", ErrorCodes::UNEXPECTED_AST_STRUCTURE);

        CompressionCodecPtr codec;
        if (codec_family_name == DEFAULT_CODEC_NAME)
            codec = current_default;
        else
            codec = getImpl(codec_family_name, codec_arguments, data_type);

        if (only_generic && !codec->isGenericCompression())
            continue;

        codecs.emplace_back(codec);
    }

    // CompressionCodecPtr res;

    if (codecs.size() == 1)
        return codecs.back();
    else if (codecs.size() > 1)
        return std::make_shared<CompressionCodecMultiple>(codecs);
    else
        return std::make_shared<CompressionCodecNone>();
}


CompressionCodecPtr CompressionCodecFactory::get(const uint8_t byte_code) const
{
    const auto family_code_and_creator = family_code_with_codec.find(byte_code);

    if (family_code_and_creator == family_code_with_codec.end())
        throw Exception("Unknown codec family code: " + toString(byte_code), ErrorCodes::UNKNOWN_CODEC);

    return family_code_and_creator->second({}, {});
}


CompressionCodecPtr CompressionCodecFactory::getImpl(const String & family_name, const Strings & arguments, const String & type) const
{
    if (family_name == "Multiple")
        throw Exception("Codec Multiple cannot be specified directly", ErrorCodes::UNKNOWN_CODEC);

    const auto family_and_creator = family_name_with_codec.find(family_name);

    if (family_and_creator == family_name_with_codec.end())
        throw Exception("Unknown codec family: " + family_name, ErrorCodes::UNKNOWN_CODEC);

    return family_and_creator->second(arguments, type);
}

void CompressionCodecFactory::registerCompressionCodecWithType(
    const String & family_name,
    std::optional<uint8_t> byte_code,
    CreatorWithType creator)
{
    if (creator == nullptr)
        throw Exception("CompressionCodecFactory: the codec family " + family_name + " has been provided a null constructor",
                        ErrorCodes::LOGICAL_ERROR);

    if (!family_name_with_codec.emplace(family_name, creator).second)
        throw Exception("CompressionCodecFactory: the codec family name '" + family_name + "' is not unique", ErrorCodes::LOGICAL_ERROR);

    if (byte_code)
        if (!family_code_with_codec.emplace(*byte_code, creator).second)
            throw Exception("CompressionCodecFactory: the codec family code '" + std::to_string(*byte_code) + "' is not unique", ErrorCodes::LOGICAL_ERROR);
}

void CompressionCodecFactory::registerCompressionCodec(const String & family_name, std::optional<uint8_t> byte_code, Creator creator)
{
    registerCompressionCodecWithType(family_name, byte_code, [family_name, creator](const Strings & parameters, const String /* data_type */)
    {
        return creator(parameters);
    });
}

void CompressionCodecFactory::registerSimpleCompressionCodec(
    const String & family_name,
    std::optional<uint8_t> byte_code,
    SimpleCreator creator)
{
    registerCompressionCodec(family_name, byte_code, [family_name, creator](const Strings & parameters)
    {
        if (parameters.size())
            throw Exception(ErrorCodes::DATA_TYPE_CANNOT_HAVE_ARGUMENTS, "Compression codec {} cannot have arguments", family_name);
        return creator();
    });
}


void registerCodecNone(CompressionCodecFactory & factory);
void registerCodecLZ4(CompressionCodecFactory & factory);
void registerCodecLZ4HC(CompressionCodecFactory & factory);
void registerCodecZSTD(CompressionCodecFactory & factory);
void registerCodecDelta(CompressionCodecFactory & factory);
void registerCodecT64(CompressionCodecFactory & factory);
void registerCodecDoubleDelta(CompressionCodecFactory & factory);
void registerCodecGorilla(CompressionCodecFactory & factory);
void registerCodecEncrypted(CompressionCodecFactory & factory);
void registerCodecMultiple(CompressionCodecFactory & factory);

CompressionCodecFactory::CompressionCodecFactory()
{
    registerCodecLZ4(*this);
    registerCodecNone(*this);
    registerCodecZSTD(*this);
    registerCodecLZ4HC(*this);
    registerCodecDelta(*this);
    registerCodecT64(*this);
    registerCodecDoubleDelta(*this);
    registerCodecGorilla(*this);
    registerCodecEncrypted(*this);
    registerCodecMultiple(*this);

    default_codec = get("LZ4", {});
}

CompressionCodecFactory & CompressionCodecFactory::instance()
{
    static CompressionCodecFactory ret;
    return ret;
}

}