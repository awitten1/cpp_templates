#include <iostream>
#include <tuple>


void print() {
}

template<typename T, typename... Types>
void print(T firstArg, Types... args) {
    using std::cout, std::endl;
    cout << firstArg << endl;
    print(args...);
}

template<typename T, typename... Types>
void print2(T firstArg, Types... args) {
    using std::cout, std::endl;
    cout << firstArg << endl;
    if constexpr (sizeof...(args) > 0) {
        print2(args...);
    } 
}

template<typename T, typename... Types>
void printNumArgs(T firstArg, Types... args) {
    using std::cout, std::endl;
    cout << sizeof...(Types) << endl;
    cout << sizeof...(args) << endl;
}

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int i = 0) : val{i}, left{nullptr}, right{nullptr} {}
};

template<typename T, typename... TP>
T traverse(T root, TP... path) {
    return (root ->* ... ->* path);
}

template<typename... T>
constexpr auto sum(T... args) {
    return (... + args);
}

template<std::size_t... I>
struct Indices {
};

template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>) {
    print(std::get<Idx>(t)...);
}

int main() {
    using std::cout, std::endl;
    // basic example
    print(4, "Asdf", 4.3);
    // demonstrates sizeof...
    printNumArgs(1, 2, 3, 4, 5);
    // demonstrates constexpr if
    print2(3, 2, 4, 5, 5);

    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->right = new Node(1);
    root->right = new Node(3);
    auto left = &Node::left;
    auto right = &Node::right;
    auto node = traverse(root, left, right);
    cout << "node: " << node->val << endl; 

    cout << "1 + 2 + 3 + 4 + 5 = " << sum(1, 2, 3, 4, 5) << endl;

    printByIdx(std::make_tuple("zeroeth", "first", "second", "third", "fourth"), Indices<4, 3, 1, 0>());
}

