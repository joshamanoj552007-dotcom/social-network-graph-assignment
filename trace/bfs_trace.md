# BFS Trace Table

Starting vertex: **A**

| Step | Queue before processing | Vertex processed | New vertices added | Queue after processing | BFS output |
|---|---|---|---|---|---|
| 1 | A | A | B, C | B, C | A |
| 2 | B, C | B | D, E | C, D, E | A B |
| 3 | C, D, E | C | F | D, E, F | A B C |
| 4 | D, E, F | D | None | E, F | A B C D |
| 5 | E, F | E | None | F | A B C D E |
| 6 | F | F | None | Empty | A B C D E F |

### Observation

BFS visits vertices level by level. Starting from A, it first visits B and C, then D, E, and F. With the adjacency matrix, neighbours are checked from A through F in label order, producing:

**A → B → C → D → E → F**

The adjacency-list traversal can have a different order because the linked-list insertion order is different, but it still visits every reachable vertex exactly once.
