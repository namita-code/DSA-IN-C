#include <stdio.h>
#define N 5 // Size of the circular queue

int queue[N];
int front = -1;
int rear = -1;

// Function to add an element to the circular queue
void enqueue(int data) {
    if ((rear + 1) % N == front) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    } else {
        if (front == -1) {
            front = 0; // First element being added
        }
        rear = (rear + 1) % N; // Move rear circularly
        queue[rear] = data;
        printf("%d enqueued successfully.\n", data);
    }
}

// Function to remove an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", queue[front]);
        if (front == rear) {
            // If the queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % N; // Move front circularly
        }
    }
}

// Function to display the circular queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break; // Stop when we reach the rear
            }
            i = (i + 1) % N; // Move circularly
        }
        printf("\n");
    }
}

// Main function with menu
int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
