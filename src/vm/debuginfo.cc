#include "support/platform.h"

#include <iostream>



extern "C" void register_eh_frames(uint8_t *Addr, size_t Size) {
    std::cout << "not impl register_eh_frames " << std::endl;
}

extern "C" void deregister_eh_frames(uint8_t *Addr, size_t Size) {
    std::cout << "not impl deregister_eh_frames " << std::endl;
}