#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create() {
    int val;
    struct node *newnode;

    printf("Enter data for node : ");
    scanf("%d", &val);

    if(val == -1)
        return NULL;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->left = NULL;
    newnode->right = NULL;

    printf("Enter left node of : %d\n", val);
    newnode->left = create();

    printf("Enter right node of : %d\n", val);
    newnode->right = create();

    return newnode;
}

void Inorder(struct node *root) {
    if(root != NULL) {
        Inorder(root->left);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root) {
    if(root != NULL) {
        printf(" %d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root) {
    if(root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ", root->data);
    }
}

int search(struct node *root, int key) {

    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    else if(search(root->left, key) || search(root->right, key))
        return 1;

    else
        return 0;
}

int main() {

    int key;
    struct node *root;

    root = create();

    printf("\nInorder Traversal : ");
    Inorder(root);

    printf("\nPreorder Traversal : ");
    Preorder(root);

    printf("\nPostorder Traversal : ");
    Postorder(root);

    printf("\nEnter key to search : ");
    scanf("%d", &key);

    if(search(root, key))
        printf("Found !!");
    else
        printf("Not Found !!");

    return 0;
}
