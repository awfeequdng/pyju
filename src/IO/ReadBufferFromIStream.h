#pragma once

#include <iostream>

#include <IO/ReadBuffer.h>
#include <IO/BufferWithOwnMemory.h>


namespace PYJU
{

class ReadBufferFromIStream : public BufferWithOwnMemory<ReadBuffer>
{
private:
    std::istream & istr;

    bool nextImpl() override;

public:
    explicit ReadBufferFromIStream(std::istream & istr_, size_t size = PYJU_DEFAULT_BUFFER_SIZE);
};

}
