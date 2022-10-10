#pragma once

#include <boost/noncopyable.hpp>

namespace PYJU
{
// http://stackoverflow.com/questions/18315472/https-request-in-c-using-poco
struct UseSSL : private boost::noncopyable
{
    UseSSL();
    ~UseSSL();
};
}
