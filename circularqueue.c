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
    if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX))
        return 1;  // Queue is full
    else
        return 0;  // Space available
}

int isEmpty() {
    if (front == -1)
        return 1;  // Queue is empty
    else
        return 0;  // Elements exist
}

int enqueue() {
    int value;
    int status = isFull();
    if (status == 1)
        return 0;  // Cannot insert

    printf("Enter the number to enqueue: ");
    scanf("%d", &value);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    return 1;
}

int dequeue() {
    int status = isEmpty();
    if (status == 1)
        return 0;  // Cannot delete

    printf("\n%d dequeued from queue", queue[front]);

    if (front == rear) {
        front = rear = -1;  // Queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }

    return 1;
}

int display() {
    int status = isEmpty();
    if (status == 1)
        return 0;  // Nothing to display

    printf("\nQueue elements are: ");
    int i = front;
    while (1) {
        printf("%d\t", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    return 1;
}
