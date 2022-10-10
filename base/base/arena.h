#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include "base/nonnull.h"

namespace PYJU
{
class Arena {
public:
    // Allocates an object in the arena, returning a pointer to it.
    template <typename T, typename... Args,
              typename std::enable_if_t<std::is_constructible_v<T, Args...>>* = nullptr>
    auto New(Args&&... args) -> Nonnull<T*> {
        auto smart_ptr = std::make_unique<ArenaEntryTyped<T>>(std::forward<Args>(args)...);
        Nonnull<T*> ptr = smart_ptr->Instance();
        arena_.push_back(std::move(smart_ptr));
        return ptr;
    }
private:
    class ArenaEntry {
        public:
        virtual ~ArenaEntry() = default;
    };
    template <typename T>
    class ArenaEntryTyped : public ArenaEntry {
    public:
        template <typename... Args>
        explicit ArenaEntryTyped(Args&&... args)
            : instance_(std::forward<Args>(args)...) {}
        auto Instance() -> Nonnull<T*> { return Nonnull<T*>(&instance_); }
    private:
        T instance_;
    };

    std::vector<std::unique_ptr<ArenaEntry>> arena_;
};

} // namespace PYJU
