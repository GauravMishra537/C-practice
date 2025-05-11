#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    int data;
    struct linkedlist *next;
} node;

node *head = NULL, *tail = NULL, *temp = NULL, *newnode = NULL;

int insert_end();
int insert_begin();
int insert_at_position();
int display();
int delete_last();
int delete_begin();
int delete_specific();

int main() {
    int choice, status;

    while (1) {
        printf("\n\nMenu:");
        printf("\n1. Insert at End");
        printf("\n2. Display");
        printf("\n3. Delete Last Node");
        printf("\n4. Insert at Beginning");
        printf("\n5. Insert at Position");
        printf("\n6. Delete First Node");
        printf("\n7. Delete Specific Node by Value");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: status = insert_end();
                printf(status == 0 ? "\nMemory allocation failed" : "\nData inserted at end"); break;
            case 2: status = display();
                printf(status == 0 ? "\nList is empty" : "\nData displayed"); break;
            case 3: status = delete_last();
                printf(status == 0 ? "\nList is empty" : "\nLast node deleted"); break;
            case 4: status = insert_begin();
                printf(status == 0 ? "\nMemory allocation failed" : "\nData inserted at beginning"); break;
            case 5: status = insert_at_position();
                printf(status == 0 ? "\nInsertion failed" : "\nData inserted at position"); break;
            case 6: status = delete_begin();
                printf(status == 0 ? "\nList is empty" : "\nFirst node deleted"); break;
            case 7: status = delete_specific();
                printf(status == 0 ? "\nNode not found or list is empty" : "\nNode deleted"); break;
            case 8:
                printf("\nExiting program.\n");
                exit(0);
            default: printf("\nInvalid choice.");
        }
    }
    return 0;
}

int insert_end() {
    int no;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) return 0;

    printf("Enter data: ");
    scanf("%d", &no);
    newnode->data = no;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head;
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
    return 1;
}

int insert_begin() {
    int no;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) return 0;

    printf("Enter data: ");
    scanf("%d", &no);
    newnode->data = no;

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
    return 1;
}

int insert_at_position() {
    int pos, no, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &no);

    if (pos == 1)
        return insert_begin();

    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) return 0;
    newnode->data = no;

    temp = head;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) return 0;

    newnode->next = temp->next;
    temp->next = newnode;

    if (temp == tail) {
        tail = newnode;
        tail->next = head;
    }

    return 1;
}

int display() {
    if (head == NULL) return 0;

    temp = head;
    printf("\nCircular Singly Linked List:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");

    return 1;
}

int delete_begin() {
    if (head == NULL) return 0;

    temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }

    free(temp);
    return 1;
}

int delete_last() {
    if (head == NULL) return 0;

    if (head == tail) {
        free(head);
        head = tail = NULL;
        return 1;
    }

    temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    temp->next = head;
    free(tail);
    tail = temp;

    return 1;
}

int delete_specific() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (head == NULL) return 0;

    if (head->data == key)
        return delete_begin();

    temp = head;
    while (temp->next != head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == head) return 0;

    node *del = temp->next;
    temp->next = del->next;

    if (del == tail) {
        tail = temp;
    }

    free(del);
    return 1;
}
