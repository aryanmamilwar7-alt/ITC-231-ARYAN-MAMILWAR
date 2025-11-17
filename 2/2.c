#include<stdio.h>
int max=10;
int top=-1;
int s[10];
void push();
void pop();
void palindrome();
void overunder();
void display();
int main(){
    int i , n;
    do{
    printf("1.for push \n 2.for pop \n 3.for pali \n 4.for overunder \n 5.for display ");
    scanf ("%d",&n);
    switch (n)
    {
    case 1:
        printf("\n your choice is push ");
        push(s);
        break;
    case 2:
        printf (" your choice is pop ");
        pop();
        break;
    case 3:
        printf(" your choice is pali");
        palindrome(max);
        break;
    case 4:
        printf(" your choice is overunder");
        overunder(max);
        break; 
    case 5:
         printf(" your choice is display "); 
         display(max,s);  
         break;  
    case 0:
        printf("exiting the program");
        exit(0);
    default:
        break;
    }
}while(1);
    return 0;
}
void push(int s[max]){
    int ele;
    printf(" \n Enter the element you want to push ");
    scanf("%d",&ele);
    if(top==max-1){
        printf("stack is overflow ");
    }else{
        top++;
        s[top]=ele;
    }
}
void pop(){
    if(top==-1){
        printf("stack is underflow ");
    }else{
        top--;
    }
}
void palindrome(int max){
    int i;
    for(i=0;i<max/2;i++){
        if(s[i]=!s[max-1-i]){
            printf("stack is not palindrome ");
            break;
        }else{
            while(i=4){
                printf("stack is palidrome ");
            }continue;
        }
    }
}
void overunder(int max){
    if(top==-1){
        printf("stack is underflow ");
    }else if(top==max-1){
        printf("stack is overflow ");
    }else{
        printf("stack is neither overflow nor underflow ");
    }
}
void display(int max , int s[max]){
    int i;
    for(i=0;i<max;i++){
        printf("%d  ",s[i]);
    }
}
