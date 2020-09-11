# Least Recently Used (LRU) Cache

LRU Cache is a cache algorithm that holds items in the order of its last access, allowing us to identify which item is not being used the longest.

## Implementation

- Cache Interface
- LRUCache Class (Hash Table) as the main structure using the Cache Interface
- List Class (Double Linked List) as a sub-structure of the LRUCache Class

## Analysis

### Time usage

- Insert key-value pair

Inserting a key-value pair involves various steps.

```
if (this->size == this->max_size) {
  this->evict();
}
if (this->get_value_from_key(key) == nullptr) {
  ++this->size;
  this->insert(key, value);
} else {
  this->update(key, value);
}
```

**Eviction**

```
auto node = this->ordered_list.front();
unsigned index = this->hash(node->content.first);
this->hash_table[index] = nullptr;
this->ordered_list.pop_front();
```

**Insert**

```
auto node = this->ordered_list.front();
unsigned index = this->hash(node->content.first);
this->hash_table[index] = nullptr;
this->ordered_list.pop_front();
```

**Update**

```
unsigned index = this->hash(key);
auto node = this->hash_table[index];
node->content.second = value;
this->ordered_list.move_back(node);
```

First, all hash operations take O(1) time because we are only calculating the hash value from the key value. Second, the search using the `[]` operator take O(1) time because we are accessing a fixed size array. Third, the ordered list operations take O(1) time because these don't involve iterating through all the members and are done by only switching pointers.

- Get most recent key

```
auto node = this->ordered_list.back();
if (node == nullptr) return nullptr;
return &node->content.first;
```

Accessing the list's tail takes O(1) time.

- Get value from key

```
unsigned index = this->hash(key);
auto node = this->hash_table[index];
if (node == nullptr) return nullptr;
this->ordered_list.move_back(node);
return &node->content.second;
```

As explained before, hash and list operations take O(1) time.

In conclusion, these 3 methods can be done in O(1) time and are optimal.

### Space usage

A LRUCache instance uses a max size attribute to limit its size, so it denotes a constant space use O(1).

## Build and test

On Linux\Unix:

```
conda env create -f conda/environment.yml
./build.sh
./build/lrucache-gtest
```

On Windows:

> You can use the MSBuild command line tool or simply use Visual Studio or any IDE of your choice to build the project.
