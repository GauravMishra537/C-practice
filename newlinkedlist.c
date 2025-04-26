#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    int data;
    struct linkedlist *next;
} lists;

lists *newnode = NULL, *head = NULL, *tail = NULL, *temp = NULL, *prev = NULL;

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
            case 1:
                status = insert_end();
                printf(status == 0 ? "\nNot enough space" : "\nData inserted successfully");
                break;
            case 2:
                status = display();
                printf(status == 0 ? "\nList is empty" : "\nData displayed");
                break;
            case 3:
                status = delete_last();
                printf(status == 0 ? "\nNothing to delete (List is empty)" : "\nLast node deleted");
                break;
            case 4:
                status = insert_begin();
                printf(status == 0 ? "\nNot enough space" : "\nData inserted at beginning");
                break;
            case 5:
                status = insert_at_position();
                printf(status == 0 ? "\nInsertion failed" : "\nData inserted at position");
                break;
            case 6:
                status = delete_begin();
                printf(status == 0 ? "\nNothing to delete (List is empty)" : "\nFirst node deleted");
                break;
            case 7:
                status = delete_specific();
                printf(status == 0 ? "\nNode not found or list is empty" : "\nSpecific node deleted");
                break;
            case 8:
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }

    return 0;
}

int insert_end() {
    int no;
    newnode = (lists *)malloc(sizeof(lists));
    if (newnode == NULL) return 0;

    printf("\nEnter a number: ");
    scanf("%d", &no);
    newnode->data = no;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    return 1;
}

int insert_begin() {
    int no;
    newnode = (lists *)malloc(sizeof(lists));
    if (newnode == NULL) return 0;

    printf("\nEnter a number: ");
    scanf("%d", &no);
    newnode->data = no;
    newnode->next = head;
    head = newnode;

    if (tail == NULL)
        tail = newnode;

    return 1;
}

int insert_at_position() {
    int pos, no, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &no);

    newnode = (lists *)malloc(sizeof(lists));
    if (newnode == NULL) return 0;

    newnode->data = no;
    newnode->next = NULL;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL)
            tail = newnode;
        return 1;
    }

    temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return 0;

    newnode->next = temp->next;
    temp->next = newnode;

    if (newnode->next == NULL)
        tail = newnode;

    return 1;
}

int display() {
    temp = head;
    if (temp == NULL) return 0;

    printf("\nLinked List Contents:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 1;
}

int delete_last() {
    temp = head;
    if (temp == NULL) return 0;

    prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(head);
        head = tail = NULL;
    } else {
        prev->next = NULL;
        tail = prev;
        free(temp);
    }

    return 1;
}

int delete_begin() {
    if (head == NULL) return 0;

    temp = head;
    head = head->next;
    free(temp);

    if (head == NULL)
        tail = NULL;

    return 1;
}

int delete_specific() {
    int key;
    printf("\nEnter the value to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return 0;

    if (prev == NULL) {
        head = head->next;
        free(temp);
        if (head == NULL)
            tail = NULL;
    } else {
        prev->next = temp->next;
        if (temp == tail)
            tail = prev;
        free(temp);
    }

    return 1;
}
