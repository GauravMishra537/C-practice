#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    int data;
    struct linkedlist *next;
} lists;

lists *newnode = NULL, *head = NULL, *tail = NULL, *temp = NULL,*prev=NULL;

int insert_end();
int display();
int delete_last();

int main() {
    int choice, status;

    while (1) {
        printf("\n\nMenu:");
        printf("\n1. Insert Data at End");
        printf("\n2. Display Data");
        printf("\n3. Delete Last Node");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                status = insert_end();
                if (status == 0)
                    printf("\nNot enough space");
                else
                    printf("\nData inserted successfully");
                break;

            case 2:
                status = display();
                if (status == 0)
                    printf("\nList is empty");
                    else
                    printf("Data displayed");
                break;

            case 3:
                status = delete_last();
                if (status == 0)
                    printf("\nNothing to delete (List is empty)");
                else
                    printf("\nLast node deleted");
                break;

            case 4:
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

    if (newnode == NULL)
        return 0;

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

int display() {
    temp = head;

    if (temp == NULL)
        return 0;

    printf("\nLinked List Contents:");
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }

    return 1;
}

int delete_last() {
    
        temp = head;
        if (temp== NULL) {
            return 0;
        }
    
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
