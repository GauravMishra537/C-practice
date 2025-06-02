#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Modified helper functions
int isFull();
int isEmpty();
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- DEQUE MENU ---");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}

// Return 0 if full (true), 1 if not full (false)
int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 0; // FULL
    return 1;     // Not full
}

// Return 0 if empty (true), 1 if not empty (false)
int isEmpty() {
    if (front == -1)
        return 0; // EMPTY
    return 1;     // Not empty
}

void insertFront(int value) {
    if (isFull() == 0) {
        printf("Deque is full!");
        return;
    }

    if (isEmpty() == 0) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }

    deque[front] = value;
    printf("Inserted %d at front", value);
}

void insertRear(int value) {
    if (isFull() == 0) {
        printf("Deque is full!");
        return;
    }

    if (isEmpty() == 0) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }

    deque[rear] = value;
    printf("Inserted %d at rear", value);
}

void deleteFront() {
    if (isEmpty() == 0) {
        printf("Deque is empty!");
        return;
    }

    printf("Deleted %d from front", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void deleteRear() {
    if (isEmpty() == 0) {
        printf("Deque is empty!");
        return;
    }

    printf("Deleted %d from rear", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
}

void display() {
    if (isEmpty() == 0) {
        printf("Deque is empty!");
        return;
    }

    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}
