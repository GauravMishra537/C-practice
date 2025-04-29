#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int enqueue();
int dequeue();
int isFull();
int isEmpty();
int display();

int queue[MAX];
int front = -1;
int rear = -1;

int main() {
    int choice, status;
    while (1) {
        printf("\n1. ENQUEUE (INSERT DATA)");
        printf("\n2. DEQUEUE (DELETE DATA)");
        printf("\n3. DISPLAY QUEUE");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                status = enqueue();
                if (status == 0)
                    printf("\nQueue is Full (Overflow)");
                else
                    printf("\nData enqueued (inserted) successfully");
                break;

            case 2:
                status = dequeue();
                if (status == 0)
                    printf("\nQueue is Empty (Underflow)");
                else
                    printf("\nData dequeued (deleted) successfully");
                break;

            case 3:
                status = display();
                if (status == 0)
                    printf("\nQueue is Empty (Nothing to display)");
                else
                    printf("\nQueue displayed successfully");
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice, please try again.");
        }
    }

    return 0;
}

int isFull() {
    if (rear == MAX - 1)
        return 0;  // Queue is full
    else
        return 1;  // Space available
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 0;  // Queue is empty
    else
        return 1;  // Elements exist
}

int enqueue() {
    int value, status;
    status = isFull();
    if (status == 0)
        return 0;

    printf("Enter the number to enqueue: ");
    scanf("%d", &value);

    rear++;

    if (rear == 0)
        front ++;

    
    queue[rear] = value;
    return 1;
}

int dequeue() {
    int status;
    status = isEmpty();
    if (status == 0)
        return 0;

    printf("\n%d dequeued from queue", queue[front]);
    front++;
    return 1;
}

int display() {
    int status;
    status = isEmpty();
    if (status == 0)
        return 0;

    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", queue[i]);
    }
    return 1;
}
