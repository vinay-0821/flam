# flam

## Q1: Least Recently Used (LRU) Cache

###  Problem Summary:
Implemented a **Least Recently Used (LRU)** Cache with the following functionalities:
- `get(key)`: Returns the value for a given key if it exists, else returns -1.
- `put(key, value)`: Inserts or updates a key-value pair. If the cache exceeds capacity, the **least recently used** item is evicted.

### Constraints:
- All operations must be **O(1)** time.
- Maximum 10^5 operations.
- Capacity: 1 ≤ capacity ≤ 3000

### Approach:
- Used **`HashMap`** for fast key lookups.
- Used a **doubly linked list** to maintain order of usage (most recently used at the front).
- On `get()`, the node is moved to the front.
- On `put()`, if key exists, update and move to front. If capacity is exceeded, evict the least recently used node (from tail).

### Technologies:
- C++ STL
- Custom `Node` class for linked list
- `unordered_map` for constant time access

## Q2: Custom HashMap Implementation

### Required Operations:
- `put(key, value)` → Insert or update the value by key.
- `get(key)` → Return the value associated with the key. If not found, return -1.
- `remove(key)` → Remove the key from the map.

## Constraints

- All keys and values are integers.
- `0 <= key, value <= 10^6`
- Maximum operations: `10^5`
- All operations must run in **O(1)** average-case time complexity.
- Do **not use** built-in hash map libraries.

## Approach Used

To meet the O(1) access requirement and the constraint on the maximum key value, we use a **fixed-size array** of length `1,000,001`. Each index in the array directly represents a key, and the value at that index stores the mapped value.

### Data Structure:
- An array of size `1e6 + 1` (`1000001`) initialized with `-1` to indicate that a key is not present.
- Direct indexing into the array using the key provides **constant time access** for all operations.


## Why this works?

Because the range of keys is limited and known (`0` to `10^6`), we can **preallocate** an array of fixed size and directly use the key as the index. This ensures:

- `put`, `get`, and `remove` operations run in **O(1)** time.
- No need for complex hashing or collision resolution.

