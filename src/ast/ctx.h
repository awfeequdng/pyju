#include <memory>
#include <list>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <assert.h>

#include <fmt/format.h>

namespace PYJU {
template <typename T>
class Context : public std::enable_shared_from_this<Context<T>> {
public:
    using Item = std::shared_ptr<T>;

protected:
    using Map = std::unordered_map<std::string, std::list<Item>>;
    /// Maps a identifier to a stack of objects that share the same identifier.
    /// Each object is represented by a nesting level and a pointer to that object.
    /// Top of the stack is the current block; the bottom is the outer-most block.
    /// Stack is represented as std::deque to allow iteration and access to the outer-most
    /// block.
    Map map;
    /// Stack of blocks and their corresponding identifiers. Top of the stack is the
    /// current block.
    std::deque<std::list<std::string>> stack;

private:
    // set of current context flags.
    std::unordered_set<std::string> flags;
    // the absolute path of the current module.
    std::string filename;

public:
    explicit Context(std::string filename) : filename(std::move(filename)) {
        // add a top-level block to the stack
        stack.push_front(std::list<std::string>());
    }
    virtual ~Context() = default;

    // add an object to the top of the stack
    virtual void add(const std::string &name, const Item &var) {
        assert(!name.empty() && "adding an empty identifier");
        map[name].push_front(var);
        stack.front().push_back(name);
    }

    void remove(const std::string &name) {

    }

    // pretty-prints the current context state.
    virtual void dump() {}

private:
    // remove an identifier from the map only.
    void removeFromMap(const std::string &name) {
        auto i = map.find(name);
        if (i == map.end())
            return;
        assert(i->second.size() && fmt::format("identifier {} not found in the map", name));
        i->second.pop_front();
        if (!i->second.size())
            map.erase(name);
    }
};

}