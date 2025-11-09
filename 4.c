#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode = NULL, *temp;
    int c = 1, count = 0;

    while (c) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter any value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1): ");
        scanf("%d", &c);
        count++;
    }

    temp = head;
    printf("\nLinked List:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Number of elements = %d\n", count);

    return 0;
}