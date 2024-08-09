#ifndef LRU_CACHE_HPP_
#define LRU_CACHE_HPP_

#include <list>
#include <unordered_map>

class LRUCacheNode {
  public:
    int key;
    int value;
    LRUCacheNode(int key, int value);
};

class LRUCache {
  private:
    int capacity;
    std::unordered_map<int, std::list<LRUCacheNode>::iterator> keyIndex;
    std::list<LRUCacheNode> cacheContainer;

  public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

  private:
    void touchNode(LRUCacheNode &node);
    void evictNode();
};

#endif // LRU_CACHE_HPP_