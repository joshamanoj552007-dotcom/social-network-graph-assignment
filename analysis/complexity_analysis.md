# Complexity Analysis

Let:

- **V** = number of vertices
- **E** = number of edges

For this graph:

- V = 6
- E = 6
- Maximum possible edges in an undirected graph with 6 vertices = V(V-1)/2 = 15
- Actual edges = 6, so the graph is relatively sparse.

## 1. Adjacency Matrix

The matrix stores a value for every possible pair of vertices.

- Space: **O(V²)**
- BFS: **O(V²)**
- DFS: **O(V²)**
- Edge existence check: **O(1)**
- Edge insertion: **O(1)**
- Edge deletion: **O(1)**

For this graph, the matrix contains **6 × 6 = 36 cells**.

## 2. Adjacency List

The list stores only the neighbours that actually exist.

- Space: **O(V + E)**
- BFS: **O(V + E)**
- DFS: **O(V + E)**
- Edge existence check: **O(degree(v))**, worst case **O(V)**
- Edge insertion: **O(1)** when inserting at the beginning
- Edge deletion: **O(degree(v))**

Because the graph is undirected, each of the 6 edges is stored twice in the adjacency lists, once for each endpoint.

## 3. Vertex Search

The program searches the vertex labels sequentially.

For target F:

A → 1 operation  
B → 2 operations  
C → 3 operations  
D → 4 operations  
E → 5 operations  
F → 6 operations

Therefore:

- Best case: **O(1)**
- Worst case: **O(V)**
- Average case: **O(V)**

The same label-search process is used for both representations, so the recorded number of label comparisons is the same for a given target.
