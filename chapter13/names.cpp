
#include <iostream>


using std::cout, std::endl;

template<typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

namespace BigMath {
    struct BigNumber {
        int x;
    };
    bool operator< (BigNumber const& a, BigNumber const& b) {
        return a.x < b.x;
    }
    bool operator + (BigNumber const& a, BigNumber const& b) {
        return a.x < b.x;
    }
}

using BigMath::BigNumber;

auto g(BigNumber const& a, BigNumber const& b) {
    return ::max(a, b);
}

int main() {
    // Two major concepts:
    // 1.  A name is a qualified name if the scope to which it belongs is explicitly
    //     denoted using scope resolution operator :: or a member access operator . or ->.
    // 2.  A name is a dependent name if it depends in some way on a template parameter.
    //     For example, any type trait.  Like typename std::decay<T>::type.
    cout << max(3, 4) << endl;
    cout << g({5}, {4}).x << endl;
}