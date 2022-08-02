#include <type_traits>
#include <iostream>

template<typename T>
auto max (T a, T b) {
    return b<a?a:b;
}

int main() {
    using namespace std;
    cout << ::max(4, 5) << endl;
}