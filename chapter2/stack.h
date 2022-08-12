#include <vector>
#include <cassert>
#include <iostream>

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
    friend std::ostream& operator<< (std::ostream& strm, const Stack<T>& s) {
        std::copy(s.elems.begin(), s.elems.end(), std::ostream_iterator<T>(std::cout, ", "));
        return strm;
    }
};


template <typename T>
class Stack<T*> {
private:
    std::vector<T*> elems;

public:
    void push(T* elem) {
        elems.push_back(elem);
    }
    void pop() {
        assert(!empty());
        elems.pop_back();
    }
    const T* top() const {
        assert(!empty());
        return elems.back();
    }
    bool empty() const {
        return elems.empty();
    }
    friend std::ostream& operator<< (std::ostream& strm, const Stack<T*>& s) {
        std::copy(s.elems.begin(), s.elems.end(), std::ostream_iterator<T*>(std::cout, "..."));
        return strm;
    }
};