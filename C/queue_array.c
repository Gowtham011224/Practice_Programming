#include<stdio.h>
#define n 5
int c=0;
int menu()
{   
    int ch;
    printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Count of elements\n4.Display queue\n5.End\nChoice:");
    scanf("%d",&ch);
    return ch;
}
void Enqueue(int q[],int a)
{
q[c]=a;
c++;
printf("Element added to Queue Successfully!\n");
return;
}
void Dequeue(int q[])
{
    int e=q[0];
    for(int i=0;i<c;i++)
    q[i]=q[i+1];
    c--;
    printf("Element(%d) Dequeued Successfully!\n",e);
    return;
}
void display(int q[])
{
    if(c==0)
    {
    printf("Queue empty!\n");
    return;
    }
    printf("Queue:\n");
    for (int i=0;i<c;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
    return;
}
void main()
{
    int q[n];int m=1;
    int ch,f=1;
    int num;
    while(m!=0)
    {
        ch=menu();
    switch(ch)
    {
        case 1:
        if(f==1)
        {
        if(c==n)
        {
        printf("Queue overflow!\n");
        break;
        }
        printf("Enter number:");
        scanf("%d",&num);
        Enqueue(q,num);
        }
        else
        printf("Can't use enqueue operation now!\n");
        break;
        case 2:
        if(c==1)
        f=1;
        else if(c!=0)
        f=0;
        if(c==0)
        {
            printf("Queue underflow!\n");
            break;
        }
        Dequeue(q);
        break;
        case 3:
        printf("Count:%d\n",c);
        break;
        case 4:
        display(q);
        break;
        case 5:
        m=0;
        break;
        default:
        printf("Invalid Input!\n");
        break;
    }
    }
}