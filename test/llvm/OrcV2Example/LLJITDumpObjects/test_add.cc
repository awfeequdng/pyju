
#include <iostream>

extern "C" int add(int);

int main() {
    std::cout << "add(101) = " << add(101) << std::endl;
    return 0;
}