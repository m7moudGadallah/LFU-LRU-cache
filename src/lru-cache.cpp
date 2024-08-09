#include "../include/lru-cache.hpp"

LRUCacheNode::LRUCacheNode(int key, int value) : key(key), value(value) {}

LRUCache::LRUCache(int capacity) : capacity(capacity) {}

int LRUCache::get(int key) {
    if (keyIndex.count(key)) {
        auto it = keyIndex[key];
        int value = it->value;
        touchNode(*it);
        return value;
    }

    return -1;
}

void LRUCache::put(int key, int value) {
    if (capacity <= 0)
        return;

    if (keyIndex.count(key)) { // node already exists
        auto it = keyIndex[key];
        it->value = value;
        touchNode(*it);
    } else {
        if ((int)keyIndex.size() >= capacity) {
            evictNode();
        }
        LRUCacheNode newNode(key, value);
        touchNode(newNode);
    }
}

void LRUCache::touchNode(LRUCacheNode &node) {
    int key = node.key;
    int value = node.value;

    // If the node is already in the cache, remove it from its current
    // position
    if (keyIndex.count(key)) {
        auto it = keyIndex[key];
        keyIndex.erase(key);
        cacheContainer.erase(it);
    }

    // Insert the node at the front of the list
    LRUCacheNode newNode(key, value);
    cacheContainer.emplace_front(newNode);

    // Update the map with the new iterator
    keyIndex[key] = cacheContainer.begin();
}

void LRUCache::evictNode() {
    if (!cacheContainer.empty()) {
        keyIndex.erase(cacheContainer.back().key);
        cacheContainer.pop_back();
    }
}