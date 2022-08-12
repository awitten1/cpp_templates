
#include <string>
#include <iostream>

#include "stack.h"

int main() {
    Stack<int> intStack;
    Stack<int*> intPtrStack;
    Stack<std::string> stringStack;
    intStack.push(1);
    intStack.push(3);
    intStack.push(5);

    intPtrStack.push(new int{4});
    intPtrStack.push(new int{7});
    intPtrStack.push(new int{8});

    std::cout << intStack << std::endl;
    std::cout << intPtrStack << std::endl;

    return 0;
}