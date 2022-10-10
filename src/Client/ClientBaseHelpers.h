#pragma once

#include <Core/Types.h>
#include <Common/config.h>

#if USE_REPLXX
#   include <base/ReplxxLineReader.h>
#endif


namespace PYJU
{

/// Should we celebrate a bit?
bool isNewYearMode();

bool isChineseNewYearMode(const String & local_tz);

#if USE_REPLXX
void highlight(const String & query, std::vector<replxx::Replxx::Color> & colors);
#endif

}
