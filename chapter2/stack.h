#include <vector>
#include <cassert>

template <typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    void push(const T& elem) {
        elems.push_back(elem);
    }
    void pop() {
        assert(!empty());
        elems.pop_back();
    }
    const T& top() const {
        assert(!empty());
        return elems.back();
    }
    bool empty() const {
        return elems.empty();
    }
};