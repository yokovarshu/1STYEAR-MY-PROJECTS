#include <stdio.h>
int adj[10][10], visited[10], n;
int queue[10], front = -1, rear = -1; 
void enqueue(int v) {
    if (rear == n - 1)
        return;
    else {
        if (front == -1) front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    if (front == -1)
        return -1;
    else {
        int item = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return item;
    }
}

// BFS function
void BFS(int start) {
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != -1) {
        int v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// DFS function
void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// Main function
int main() {
    int i, j, choice, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. BFS Traversal\n");
        printf("2. DFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                BFS(start);
                break;

            case 2:
                for (i = 0; i < n; i++)
                    visited[i] = 0;

                printf("Enter starting vertex: ");
                scanf("%d", &start);

                printf("DFS Traversal: ");
                DFS(start);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

