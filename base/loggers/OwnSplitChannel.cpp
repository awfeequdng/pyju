#include "OwnSplitChannel.h"
#include "OwnFormattingChannel.h"

#include <iostream>
#include <IO/WriteBufferFromFileDescriptor.h>
#include <sys/time.h>
#include <Poco/Message.h>
#include <Common/setThreadName.h>
#include <Common/LockMemoryExceptionInThread.h>
#include <base/getThreadId.h>
#include <Common/SensitiveDataMasker.h>
#include <Common/IO.h>

namespace PYJU
{
void OwnSplitChannel::log(const Poco::Message & msg)
{
    if (channels.empty())
        return;

    if (auto * masker = SensitiveDataMasker::getInstance())
    {
        auto message_text = msg.getText();
        auto matches = masker->wipeSensitiveData(message_text);
        if (matches > 0)
        {
            tryLogSplit({msg, message_text}); // we will continue with the copy of original message with text modified
            return;
        }

    }

    tryLogSplit(msg);
}


void OwnSplitChannel::tryLogSplit(const Poco::Message & msg)
{
    try
    {
        logSplit(msg);
    }
    /// It is better to catch the errors here in order to avoid
    /// breaking some functionality because of unexpected "File not
    /// found" (or similar) error.
    ///
    /// For example StorageDistributedDirectoryMonitor will mark batch
    /// as broken, some MergeTree code can also be affected.
    ///
    /// Also note, that we cannot log the exception here, since this
    /// will lead to recursion, using regular tryLogCurrentException().
    /// but let's log it into the stderr at least.
    catch (...)
    {
        LockMemoryExceptionInThread lock_memory_tracker(VariableContext::Global);

        const std::string & exception_message = getCurrentExceptionMessage(true);
        const std::string & message = msg.getText();

        /// NOTE: errors are ignored, since nothing can be done.
        writeRetry(STDERR_FILENO, "Cannot add message to the log: ");
        writeRetry(STDERR_FILENO, message.data(), message.size());
        writeRetry(STDERR_FILENO, "\n");
        writeRetry(STDERR_FILENO, exception_message.data(), exception_message.size());
        writeRetry(STDERR_FILENO, "\n");
    }
}

void OwnSplitChannel::logSplit(const Poco::Message & msg)
{
    ExtendedLogMessage msg_ext = ExtendedLogMessage::getFrom(msg);

    /// Log data to child channels
    for (auto & [name, channel] : channels)
    {
        if (channel.second)
            channel.second->logExtended(msg_ext); // extended child
        else
            channel.first->log(msg); // ordinary child
    }
}


void OwnSplitChannel::addChannel(Poco::AutoPtr<Poco::Channel> channel, const std::string & name)
{
    channels.emplace(name, ExtendedChannelPtrPair(std::move(channel), dynamic_cast<ExtendedLogChannel *>(channel.get())));
}

void OwnSplitChannel::addTextLog(std::shared_ptr<PYJU::TextLog> log, int max_priority)
{
    std::lock_guard<std::mutex> lock(text_log_mutex);
    text_log = log;
    text_log_max_priority.store(max_priority, std::memory_order_relaxed);
}

void OwnSplitChannel::setLevel(const std::string & name, int level)
{
     auto it = channels.find(name);
     if (it != channels.end())
     {
         if (auto * channel = dynamic_cast<PYJU::OwnFormattingChannel *>(it->second.first.get()))
            channel->setLevel(level);
     }
}

}
