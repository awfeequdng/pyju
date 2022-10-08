#include <Common/MemoryTracker.h>

#include <Common/CurrentMemoryTracker.h>


namespace
{

MemoryTracker * getMemoryTracker()
{
    return nullptr;
}

}

namespace CurrentMemoryTracker
{


namespace
{
    void allocImpl(Int64 size, bool throw_if_memory_exceeded)
    {
        if (auto * memory_tracker = getMemoryTracker())
        {

            memory_tracker->allocImpl(size, throw_if_memory_exceeded);

        }
    }
}

void check()
{
    if (auto * memory_tracker = getMemoryTracker())
        memory_tracker->allocImpl(0, true);
}

void alloc(Int64 size)
{
    bool throw_if_memory_exceeded = true;
    allocImpl(size, throw_if_memory_exceeded);
}

void allocNoThrow(Int64 size)
{
    bool throw_if_memory_exceeded = false;
    allocImpl(size, throw_if_memory_exceeded);
}

void realloc(Int64 old_size, Int64 new_size)
{
    Int64 addition = new_size - old_size;
    addition > 0 ? alloc(addition) : free(-addition);
}

void free(Int64 size)
{
    if (auto * memory_tracker = getMemoryTracker())
    {

        memory_tracker->free(size);
    }
}

}
