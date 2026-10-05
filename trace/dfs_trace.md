# DFS Trace Table

Starting vertex: **A**

Using the adjacency matrix and checking neighbours in alphabetical order:

| Step | Current vertex | Action | DFS output |
|---|---|---|---|
| 1 | A | Visit A, move to B | A |
| 2 | B | Visit B, move to D | A B |
| 3 | D | Visit D, backtrack to B | A B D |
| 4 | B | D already visited, move to E | A B D |
| 5 | E | Visit E, move to F | A B D E |
| 6 | F | Visit F, C is next unvisited | A B D E F |
| 7 | C | Visit C, all neighbours visited | A B D E F C |

### Final DFS order

**A → B → D → E → F → C**

### Observation

DFS follows one path as deeply as possible before backtracking. Different adjacency-list orders can produce a different valid DFS sequence.
