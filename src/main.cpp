#include "../include/lfu-cache.hpp"
#include "../include/lru-cache.hpp"
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
    std::cout << "Test LRU Cache...\n";
    LRUCache lruCache(2);
    std::cout << "put(1, 1)\n";
    lruCache.put(1, 1);
    std::cout << "put(2, 2)\n";
    lruCache.put(2, 2);
    std::cout << "get(1): " << lruCache.get(1) << "\n";
    std::cout << "put(3, 3)\n";
    lruCache.put(3, 3);
    std::cout << "get(2): " << lruCache.get(2) << "\n";
    std::cout << "get(3): " << lruCache.get(3) << "\n";
    std::cout << "put(4, 4)\n";
    lruCache.put(4, 4);
    std::cout << "get(1): " << lruCache.get(1) << "\n";
    std::cout << "get(3): " << lruCache.get(3) << "\n";
    std::cout << "get(4): " << lruCache.get(4) << "\n";
    return 0;
}
