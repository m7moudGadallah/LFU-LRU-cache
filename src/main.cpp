#include "../include/lfu-cache.hpp"
#include <iostream>

int main(void) {
    std::cout << "Test LFU Cache...\n";
    LFUCache lfuCache(2);
    std::cout << "put(1, 1)\n";
    lfuCache.put(1, 1);
    std::cout << "put(2, 2)\n";
    lfuCache.put(2, 2);
    std::cout << "get(1): " << lfuCache.get(1) << "\n";
    std::cout << "put(3, 3)\n";
    lfuCache.put(3, 3);
    std::cout << "get(2): " << lfuCache.get(2) << "\n";
    std::cout << "get(3): " << lfuCache.get(3) << "\n";
    std::cout << "put(4, 4)\n";
    lfuCache.put(4, 4);
    std::cout << "get(1): " << lfuCache.get(1) << "\n";
    std::cout << "get(3): " << lfuCache.get(3) << "\n";
    std::cout << "get(4): " << lfuCache.get(4) << "\n";
    std::cout << "-----------------------------\n";
    return 0;
}
