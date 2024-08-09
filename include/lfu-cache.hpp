#ifndef LFU_CACHE_HPP_
#define LFU_CACHE_HPP_

#include <list>
#include <unordered_map>

class LFUCacheNode {
  public:
    int key;
    int value;
    int frequency;
    LFUCacheNode(int key, int value, int frequency);
};

class LFUCache {
  private:
    int capacity;
    int minFreq;
    int cacheSize;
    std::unordered_map<int, std::list<LFUCacheNode>::iterator> keyIndex;
    std::unordered_map<int, std::list<LFUCacheNode>> frequencyIndex;

  public:
    LFUCache(int capacity);

    int get(int key);

    void put(int key, int value);

  private:
    void touchNode(std::list<LFUCacheNode>::iterator it);
    void evictNode();
};

#endif // LFU_CACHE_HPP_