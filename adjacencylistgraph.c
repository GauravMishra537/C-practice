#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Define List as a pointer to a Node
typedef struct Node {
    int vertex;
    struct Node* next;
} *List;

List adjList[MAX];

void addEdge(int src, int dest) {
    // Add edge from src to dest
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = (List)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void printGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        List temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
    for (int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d%d", &src, &dest);
        addEdge(src, dest);
    }

    printf("\nAdjacency List:\n");
    printGraph(vertices);

    return 0;
}
