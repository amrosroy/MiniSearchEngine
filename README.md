# Mini Search Engine in C++

## Features
- File indexing
- Exact word search
- Frequency-based ranking
- Case-insensitive search
- Trie-based autocomplete suggestions

## Data Structures Used
- `unordered_map`
- `vector`
- Inverted Index
- Trie

## How It Works

### Inverted Index
The project builds an inverted index of the form:

```txt
word -> filename -> frequency
```

This allows efficient exact-word searching and ranking of results based on frequency.

### Trie
The project also builds a Trie data structure for fast prefix-based autocomplete suggestions.

Example:

```txt
Input: se

Suggestions:
search
security
server
```

## Tech Stack
- C++
- STL (Standard Template Library)

## Concepts Used
- Hashing
- Trees
- Recursion
- File Handling
- OOP
- Modular Programming

## Future Improvements
- Phrase search
- Dynamic file addition
- GUI support
- Distributed indexing