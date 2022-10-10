#pragma once


#include <base/LineReader.h>
#include <thread>
#include <boost/noncopyable.hpp>

namespace PYJU
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
