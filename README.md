# Social Network Graph Assignment

## Overview

This project implements a small undirected social network graph in **C** using two graph representations:

1. Adjacency Matrix
2. Adjacency List

The graph contains the connections:

- A-B
- A-C
- B-D
- B-E
- C-F
- E-F

## Requirements Covered

- Adjacency matrix implementation
- Adjacency list implementation
- BFS starting from A
- DFS starting from A
- Vertex search with operation count
- BFS and DFS trace tables
- Time and space complexity analysis
- Comparison of both graph representations
- Final recommendation for a sparse social network

## Project Structure

```text
social-network-graph-assignment/
├── README.md
├── src/
│   └── social_network.c
├── input/
│   └── input.txt
├── output/
│   └── output.txt
├── trace/
│   ├── bfs_trace.md
│   └── dfs_trace.md
├── analysis/
│   ├── complexity_analysis.md
│   └── comparison_table.md
└── conclusion/
    └── conclusion.md
```

## Sample Traversals

Using the adjacency matrix and checking neighbours in alphabetical order:

- BFS: **A B C D E F**
- DFS: **A B D E F C**

The adjacency-list traversal may produce a different valid order because the order of neighbours in a linked list can differ.

## Sample Search

Searching for vertex **F**:

- Matrix representation: 6 label comparisons
- List representation: 6 label comparisons

## Complexity Summary

| Operation | Matrix | List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| BFS | O(V²) | O(V + E) |
| DFS | O(V²) | O(V + E) |
| Edge check | O(1) | O(degree(v)) |

## Conclusion

The graph has 6 vertices and 6 edges, so it is relatively sparse. The **adjacency list** is the recommended representation because it stores only existing connections and provides O(V + E) traversal complexity.

## How to Compile and Run

Using GCC:

```bash
gcc src/social_network.c -o social_network
./social_network
```

On Windows with MinGW:

```bash
gcc src/social_network.c -o social_network.exe
social_network.exe
```

When prompted, enter a vertex such as:

```text
F
```
