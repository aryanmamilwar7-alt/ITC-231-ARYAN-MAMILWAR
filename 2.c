#include <stdio.h>
#define MAX 10

int top = -1;
int S[MAX];

void push();
void pop();
void palindrome();
void overunderflow();
void display();

int main() {
    int ch;
    printf("Enter Choice:\n");
    printf("1 - To push element\n");
    printf("2 - To pop element\n");
    printf("3 - To check palindrome\n");
    printf("4 - To check underflow and overflow condition\n");
    printf("5 - To display stack\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: palindrome(); break;
        case 4: overunderflow(); break;
        case 5: display(); break;
        default: printf("Invalid choice\n"); break;
    }
    return 0;
}

void push() {
    int ele;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &ele);
        top++;
        S[top] = ele;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", S[top]);
        top--;
    }
}

void palindrome() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    int i;
    for (i = 0; i <= top / 2; i++) {
        if (S[i] != S[top - i]) {
            printf("Stack is Not Palindrome\n");
            return;
        }
    }
    printf("Stack is Palindrome\n");
}

void overunderflow() {
    if (top == -1)
        printf("Stack is Underflow (Empty)\n");
    else if (top == MAX - 1)
        printf("Stack is Overflow (Full)\n");
    else
        printf("Stack is neither Overflow nor Underflow\n");
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
}