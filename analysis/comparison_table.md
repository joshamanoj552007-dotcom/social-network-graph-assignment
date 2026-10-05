# Comparison Table

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Storage | O(V²) | O(V + E) |
| BFS | O(V²) | O(V + E) |
| DFS | O(V²) | O(V + E) |
| Edge checking | O(1) | O(degree(v)) |
| Edge insertion | O(1) | O(1) at head |
| Memory for sparse graph | Higher | Lower |
| Neighbour traversal | Checks all V positions | Checks only actual neighbours |
| Best suited for | Dense graphs | Sparse graphs |

## Execution-based comparison

For the given graph:

- Vertices: 6
- Edges: 6
- Possible undirected edges: 15
- Matrix cells: 36
- List stores only the six actual connections (12 neighbour entries because the graph is undirected).

The matrix is simple and provides constant-time edge checking. However, BFS and DFS scan all 6 possible neighbours for every processed vertex.

The adjacency list examines only the neighbours that actually exist. Therefore, for this sparse social network, it uses memory more efficiently and provides better traversal complexity.

## Search observation

Searching for vertex **F** required 6 label comparisons in the sequential search used by the program. This result is independent of whether the underlying graph is displayed as a matrix or list because the vertex-label array is the same.

