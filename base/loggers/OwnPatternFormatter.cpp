#include "OwnPatternFormatter.h"

#include <functional>
#include <IO/WriteBufferFromString.h>
#include <IO/WriteHelpers.h>
#include <Common/HashTable/Hash.h>
#include <base/terminalColors.h>


OwnPatternFormatter::OwnPatternFormatter(bool color_)
    : Poco::PatternFormatter(""), color(color_)
{
}


void OwnPatternFormatter::formatExtended(const PYJU::ExtendedLogMessage & msg_ext, std::string & text) const
{
    PYJU::WriteBufferFromString wb(text);

    const Poco::Message & msg = msg_ext.base;

    /// Change delimiters in date for compatibility with old logs.
    PYJU::writeDateTimeText<'.', ':'>(msg_ext.time_seconds, wb);

    PYJU::writeChar('.', wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 100000) % 10), wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 10000) % 10), wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 1000) % 10), wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 100) % 10), wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 10) % 10), wb);
    PYJU::writeChar('0' + ((msg_ext.time_microseconds / 1) % 10), wb);

    writeCString(" [ ", wb);
    if (color)
        writeString(setColor(intHash64(msg_ext.thread_id)), wb);
    PYJU::writeIntText(msg_ext.thread_id, wb);
    if (color)
        writeCString(resetColor(), wb);
    writeCString(" ] ", wb);

    /// We write query_id even in case when it is empty (no query context)
    /// just to be convenient for various log parsers.
    writeCString("{", wb);
    if (color)
        writeString(setColor(std::hash<std::string>()(msg_ext.query_id)), wb);
    PYJU::writeString(msg_ext.query_id, wb);
    if (color)
        writeCString(resetColor(), wb);
    writeCString("} ", wb);

    writeCString("<", wb);
    int priority = static_cast<int>(msg.getPriority());
    if (color)
        writeCString(setColorForLogPriority(priority), wb);
    PYJU::writeString(getPriorityName(priority), wb);
    if (color)
        writeCString(resetColor(), wb);
    writeCString("> ", wb);
    if (color)
        writeString(setColor(std::hash<std::string>()(msg.getSource())), wb);
    PYJU::writeString(msg.getSource(), wb);
    if (color)
        writeCString(resetColor(), wb);
    writeCString(": ", wb);
    PYJU::writeString(msg.getText(), wb);
}

void OwnPatternFormatter::format(const Poco::Message & msg, std::string & text)
{
    formatExtended(PYJU::ExtendedLogMessage::getFrom(msg), text);
}
