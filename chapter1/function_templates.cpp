#include <iostream>

template<typename T>
auto max (T a, T b) {
    return b<a?a:b;
}

template<typename T>
T max2 (T const& a, T const& b)
{
    return b<a?a:b; 
}

int main() {
    using namespace std;
    cout << ::max2(4, 5) << endl;
}