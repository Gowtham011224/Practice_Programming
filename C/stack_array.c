#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define n 5
int c=0;
char st1[20]="";
char st2[20]="";
int menu()
{   
    int ch;
    printf("Menu:\n1.Push\n2.Pop\n3.Count of elements\n4.Display stack\n5.Check palindrome\n6.End\nChoice:");
    scanf("%d",&ch);
    return ch;
}
void pop(int a[])
{
    if (c == 0)
    {
        printf("Stack underflow\n");
        return;
    }

    int e = a[--c];
    char temp[10];
    sprintf(temp, "%d", e);
    
    strcat(st1, temp);
    strcat(temp, st2);
    strcpy(st2, temp);

    printf("Element(%d) Popped Successfully!\n", e);
}

void push(int a[],int e)
{
a[c++]=e;
printf("Element Pushed Successfully!\n");
}
void display(int arr[])
{
    if(c==0)
    {
    printf("Stack empty!\n");
    return;
    }
    printf("Stack:\n");
    for (int i=c-1;i>=0;i--)
    {
        printf("%d \n",arr[i]);
    }
    return;
}
bool palindrome()
{
if(strcmp(st1,st2)==0)
return true;
return false;
}

void main()
{
    printf("STACK SIZE IS FIXED AT 5\n");
    int arr[n];
    int m=0;
    int ch;
    while(m!=1)
    {
        ch=menu();
    switch (ch)
    {
        case 1:
        if(c==n)
        printf("Stack overflow\n");
        else
        {
        int e;
        printf("Enter new element:");
        scanf("%d",&e);
        push(arr,e);
        }
        break;
        case 2:
        pop(arr);
        break;
        case 3:
        printf("Count:%d\n",c);
        break;
        case 4:
        display(arr);
        break;
        case 5:
        if(c==0)
        printf("Stack is empty!!\n");
        else if(strcmp(st1,"")==0)
        printf("No element poped yet!\n");
        else if(palindrome())
        printf("Poped Stack elements is palindrome\n");
        else
        printf("Poped Stack elements is not palindrome\n");
        break;
        case 6:
        m=1;
        break;
        default:
        printf("Wrong input/n");
    }
    }
}