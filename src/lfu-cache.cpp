#include "../include/lfu-cache.hpp"

LFUCacheNode::LFUCacheNode(int key, int value, int frequency)
    : key(key), value(value), frequency(frequency) {}

LFUCache::LFUCache(int capacity)
    : capacity(capacity), minFreq(0), cacheSize(0) {}

int LFUCache::get(int key) {
    if (keyIndex.count(key)) {
        auto it = keyIndex[key];
        int value = it->value;
        touchNode(it);
        return value;
    }
    return -1;
}

void LFUCache::put(int key, int value) {
    if (capacity <= 0)
        return;

    if (keyIndex.count(key)) {
        auto it = keyIndex[key];
        it->value = value;
        touchNode(it);
    } else {
        if (cacheSize >= capacity) {
            evictNode();
        }

        LFUCacheNode newNode(key, value, 1);
        frequencyIndex[1].emplace_front(newNode);
        keyIndex[key] = frequencyIndex[1].begin();
        minFreq = 1;
        ++cacheSize;
    }
}

void LFUCache::touchNode(std::list<LFUCacheNode>::iterator it) {
    int freq = it->frequency;
    int key = it->key;
    int value = it->value;

    // Remove the node from the current frequency list
    frequencyIndex[freq].erase(it);
    if (frequencyIndex[freq].empty()) {
        frequencyIndex.erase(freq);
        if (minFreq == freq) {
            minFreq++;
        }
    }

    // Increment the frequency and add to the new frequency list
    freq++;
    LFUCacheNode updatedNode(key, value, freq);
    frequencyIndex[freq].emplace_front(updatedNode);
    keyIndex[key] = frequencyIndex[freq].begin();
}

void LFUCache::evictNode() {
    // Evict the least frequently used node
    auto &list = frequencyIndex[minFreq];
    auto it = list.back();
    keyIndex.erase(it.key);
    list.pop_back();
    if (list.empty()) {
        frequencyIndex.erase(minFreq);
    }
    --cacheSize;
}