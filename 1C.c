#include<stdio.h>
struct students{
    char name[50];
    char sec;
    int age;
    int dob;
    int marks;
};
int main()
{
    struct students student[100], temp;
    int i, j, n;
    printf("enter the no of student ");
    scanf("%d", &n);
    printf("enter the details of student\n");
    for(i = 0; i < n; i++)
    {
        printf("student %d ", i+1);
        printf("enter name ");
        scanf("%s", student[i].name);
        printf("enter sec ");
        scanf(" %c", &student[i].sec);    
        printf("enter age ");
        scanf("%d", &student[i].age);
        printf("enter date of birth  ");
        scanf("%d", &student[i].dob);
        printf("enter marks ");
        scanf("%d", &student[i].marks);
    }
    printf("On the basis of average marks\n");
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){
            if(student[j].marks < student[j+1].marks){
                temp = student[j];
                student[j] = student[j+1];
                student[j+1] = temp;
            }
        }
    }  
    printf("In descending order\n");
    for(i = 0; i < n; i++)
    {
        for(i = 0; i < n; i++) {
        printf("%s\t%c\t%d\t%d\t%d\n", student[i].name, student[i].sec, student[i].age, student[i].dob, student[i].marks);
    }
    return 0;
    }