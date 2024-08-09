# LRU Cache

Read about LRU Cache [here](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU) on Wikipedia.

## Problem Statement

- Problem Statement inspired from [LeetCode 146. LRU Cache](https://leetcode.com/problems/lru-cache/description/)
- Following to the problem statement, we need to implement LRU Cache with the following operations:
  - `LRUCache(int capacity)`: Initialize the cache with a capacity.
  - `int get(int key)`: Get the value of the key if the key exists in the cache, otherwise return -1.
  - `void put(int key, int value)`: Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting a new item.

## Design

- We will use a combination of `unordered_map` and `list` to implement LRU Cache.
- We will use `unordered_map` to store the key and iterator to the node in the list.
- We will use `list` to store the nodes sorted from most recently used to least recently used.
- We will use `capacity` variable to store the capacity of the cache.

## Implementation

- Look at header file [lru_cache.h](../include/lru-cache.hpp) for the class definition.
- Look at implementation file [lru_cache.cpp](../src/lru-cache.cpp) for the class implementation.

## Complexity Analysis

**Time Complexity:**

- `get`: O(1)
- `put`: O(1)

**Space Complexity:**

- O(capacity) , where capacity is the capacity of the cache.

## Future Enhancements

- Enhance the implementation to support templated key and value types.
- Support extra functionalities like `size`, `clear`, etc.
