#pragma once


#include <base/LineReader.h>
#include <thread>
#include <boost/noncopyable.hpp>

namespace DB
{

class Suggest : public LineReader::Suggest, boost::noncopyable
{
public:
    Suggest();

    ~Suggest()
    {

    }
};

}
