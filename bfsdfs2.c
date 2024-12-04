#include<stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front = -1, i, k;
    queue[++rear] = start; // Enqueue the start node
    ++front;
    visited[start] = 1;  // Mark the start node as visited

    printf("BFS Traversal: ");

    while (rear >= front)
    {
        start = queue[front++]; // Dequeue the front node
        printf("%c->", start+65); // Print the node

        // Visit all adjacent nodes
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0) // If the node is connected and not visited
            {
                queue[++rear] = i; // Enqueue the node
                visited[i] = 1;     // Mark as visited
            }
        }
    }
    printf("\n");
}

void dfs(int adj[][MAX], int visited[], int start)
{
    int stack[MAX], top = -1, i;
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (top != -1)
    {
        start = stack[top--];
        printf("%c->", start+65);


        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
    printf("END");
}

int main()
{
    int visited[MAX], adj[MAX][MAX], i, j;
    int option;

    do
    {
        for (i = 0; i < MAX; i++)
            visited[i] = 0;

        printf("\n1. Enter values in graph");
        printf("\n2. BFS Traversal");
        printf("\n3. DFS Traversal");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter the adjacency matrix (5x5):\n");
                for(i = 0; i < MAX; i++)
                    for(j = 0; j < MAX; j++)
                        scanf("%d", &adj[i][j]);
                break;

            case 2:
                printf("BFS Traversal:\n");
                bfs(adj, visited, 0);
                break;

            case 3:
                printf("DFS Traversal:\n");
                dfs(adj, visited, 0);
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while(option != 4);

    return 0;
}
