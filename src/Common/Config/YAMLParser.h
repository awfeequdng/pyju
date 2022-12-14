#pragma once

#include <Common/config.h>

#include <string>

#include <Poco/DOM/Document.h>
#include "Poco/DOM/AutoPtr.h"
#include <base/logger_useful.h>
#include <base/types.h>

#if USE_YAML_CPP

namespace PYJU
{

/// Real YAML parser: loads yaml file into a YAML::Node
class YAMLParserImpl
{
public:
    static Poco::AutoPtr<Poco::XML::Document> parse(const String& path);
};

using YAMLParser = YAMLParserImpl;

}

#else

namespace PYJU
{

namespace ErrorCodes
{
    extern const int CANNOT_PARSE_YAML;
}

/// Fake YAML parser: throws an exception if we try to parse YAML configs in a build without yaml-cpp
class DummyYAMLParser
{
public:
    static Poco::AutoPtr<Poco::XML::Document> parse(const String& path)
    {
        Poco::AutoPtr<Poco::XML::Document> xml = new Poco::XML::Document;
        throw Exception(ErrorCodes::CANNOT_PARSE_YAML, "Unable to parse YAML configuration file {} without usage of yaml-cpp library", path);
        return xml;
    }
};

using YAMLParser = DummyYAMLParser;

}

#endif
