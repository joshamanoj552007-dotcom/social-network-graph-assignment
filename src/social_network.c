#include <stdio.h>
#include <stdlib.h>

#define V 6

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
int adjMatrix[V][V] = {0};

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *adjList[V] = {NULL};

int getIndex(char label) {
    for (int i = 0; i < V; i++) {
        if (vertices[i] == label)
            return i;
    }
    return -1;
}

Node *createNode(int vertex) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    /* Adjacency matrix */
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    /* Adjacency list */
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void createGraph(void) {
    addEdge(0, 1);  /* A-B */
    addEdge(0, 2);  /* A-C */
    addEdge(1, 3);  /* B-D */
    addEdge(1, 4);  /* B-E */
    addEdge(2, 5);  /* C-F */
    addEdge(4, 5);  /* E-F */
}

void displayMatrix(void) {
    printf("\nAdjacency Matrix:\n    ");
    for (int i = 0; i < V; i++)
        printf("%c ", vertices[i]);

    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%c   ", vertices[i]);
        for (int j = 0; j < V; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void displayList(void) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", vertices[i]);
        Node *temp = adjList[i];

        while (temp != NULL) {
            printf("%c", vertices[temp->vertex]);
            if (temp->next != NULL)
                printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfsMatrix(int start) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS using Adjacency Matrix: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%c ", vertices[current]);

        for (int i = 0; i < V; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void bfsList(int start) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS using Adjacency List: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%c ", vertices[current]);

        Node *temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsMatrixUtil(int current, int visited[]) {
    visited[current] = 1;
    printf("%c ", vertices[current]);

    for (int i = 0; i < V; i++) {
        if (adjMatrix[current][i] && !visited[i])
            dfsMatrixUtil(i, visited);
    }
}

void dfsMatrix(int start) {
    int visited[V] = {0};
    printf("\nDFS using Adjacency Matrix: ");
    dfsMatrixUtil(start, visited);
    printf("\n");
}

void dfsListUtil(int current, int visited[]) {
    visited[current] = 1;
    printf("%c ", vertices[current]);

    Node *temp = adjList[current];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfsListUtil(temp->vertex, visited);
        temp = temp->next;
    }
}

void dfsList(int start) {
    int visited[V] = {0};
    printf("DFS using Adjacency List: ");
    dfsListUtil(start, visited);
    printf("\n");
}

void searchMatrix(char target) {
    int operations = 0;
    int found = -1;

    for (int i = 0; i < V; i++) {
        operations++;
        if (vertices[i] == target) {
            found = i;
            break;
        }
    }

    printf("\nSearch '%c' using Matrix representation:\n", target);
    if (found != -1)
        printf("Vertex found at index %d. Operations = %d\n", found, operations);
    else
        printf("Vertex not found. Operations = %d\n", operations);
}

void searchList(char target) {
    int operations = 0;
    int found = -1;

    /*
     * Search the vertex labels in the same order used by the
     * adjacency-list array. The representation stores one list
     * for each vertex, so locating a vertex label requires checking
     * the vertex array.
     */
    for (int i = 0; i < V; i++) {
        operations++;
        if (vertices[i] == target) {
            found = i;
            break;
        }
    }

    printf("Search '%c' using List representation:\n", target);
    if (found != -1)
        printf("Vertex found at index %d. Operations = %d\n", found, operations);
    else
        printf("Vertex not found. Operations = %d\n", operations);
}

void freeList(void) {
    for (int i = 0; i < V; i++) {
        Node *current = adjList[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        adjList[i] = NULL;
    }
}

int main(void) {
    char target;

    createGraph();

    printf("SOCIAL NETWORK GRAPH\n");
    printf("====================\n");

    printf("Vertices: A B C D E F\n");
    printf("Edges: A-B, A-C, B-D, B-E, C-F, E-F\n");

    displayMatrix();
    displayList();

    bfsMatrix(0);
    bfsList(0);

    dfsMatrix(0);
    dfsList(0);

    printf("\nEnter vertex to search (A-F): ");
    scanf(" %c", &target);

    if (getIndex(target) == -1) {
        printf("Invalid vertex. Please enter A, B, C, D, E or F.\n");
    } else {
        searchMatrix(target);
        searchList(target);
    }

    freeList();
    return 0;
}
