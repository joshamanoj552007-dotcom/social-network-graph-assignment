# Final Conclusion

The social network graph was implemented using both an **adjacency matrix** and an **adjacency list**, and BFS and DFS were performed starting from vertex **A**. A vertex search was also implemented and the number of operations was recorded.

The adjacency matrix is easy to understand and provides **O(1)** edge checking, but it requires **O(V²)** memory and **O(V²)** time for BFS and DFS. The adjacency list requires **O(V + E)** memory and supports BFS and DFS in **O(V + E)** time.

The given social network contains 6 vertices and 6 edges, compared with 15 possible edges in a complete undirected graph. Therefore, it is relatively **sparse**. The execution and complexity analysis show that the adjacency list stores only existing connections instead of reserving space for every possible connection.

Therefore, the **adjacency list is the more suitable representation for this social network** because social networks are typically sparse: each person is connected to only a small fraction of all possible users. The adjacency matrix would be preferable when the graph is dense or when very frequent constant-time edge-existence checks are more important.
