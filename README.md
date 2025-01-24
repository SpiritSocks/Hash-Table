Hash Table Implementation
---------
Overview
This repository contains an implementation of a Hash Table in C++. The project aims to demonstrate the core operations of a hash table and to highlight handling key-value storage efficiently.

Features:
- Insertion: Add key-value pairs to the hash table.
- Search: Retrieve the value associated with a key.
- Deletion: Remove key-value pairs by their key.
- Collision Handling: Uses (specify: chaining, linear probing, or other methods).
- How It Works
- Hashing Function: (Describe the hashing function used).
- Collision Resolution

----------
Collision Handling:
Each bucket in the hash table is represented by a std::list of key-value pairs (std::pair<int, std::string>).
When multiple keys map to the same bucket, they are stored in the list for that bucket.
During operations like insertion, search, and deletion, the list in the corresponding bucket is traversed to locate the key.
