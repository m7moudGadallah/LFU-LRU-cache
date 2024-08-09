# LFU Cache

Read about LFU Cache [here](https://en.wikipedia.org/wiki/Least_frequently_used) on Wikipedia.

## Problem Statement

- Problem Statement inspired from [LeetCode 460. LFU Cache](https://leetcode.com/problems/lfu-cache/description/)
- Following to the problem statement, we need to implement LFU Cache with the following operations:
  - `LFUCache(int capacity)`: Initialize the cache with a capacity.
  - `int get(int key)`: Get the value of the key if the key exists in the cache, otherwise return -1.
  - `void put(int key, int value)`: Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

## Design

- We will use a combination of `unordered_map` and `list` to implement LFU Cache.
- We will use `unordered_map` to store the key and iterator to the node in the list.
- We will use `unordered_map` to store the frequency mapped to the list of nodes with that frequency.
- We will use `list` to store the nodes with the same frequency.
- We will use a `minFreq` variable to store the minimum frequency of the nodes in the cache.
- We will use a `capacity` variable to store the capacity of the cache.
- We will use a `cacheSize` variable to store the current size of the cache.

## Future Enhancements

- Enhance the implementation to support templated key and value types.
- Support extra functionalities like `size`, `clear`, etc.
