#include <iostream>
#include "Stacks.h"

int main() {
    Stacks<int> stack;

    for (int i = 0; i < 10; ++i) {
        stack.push2(i+1);
    }

    std::cout << stack;
    stack.pop2();

    std::cout << stack;


    return 0;
}
