#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
}*head=NULL;
struct node *trav;
int c=0;
int menu()
{   
    int ch;
    printf("Menu:\n1.Push\n2.Pop\n3.Count of elements\n4.Display stack\n5.End\nChoice:");
    scanf("%d",&ch);
    return ch;
}

void push(struct node *ptr)
{
	ptr->next=head;
	head=ptr;
    c++;
    printf("Element added.\n");
}

void pop()
{
    if(head==NULL)
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
    c--;
    printf("Element(%d) Poped Successfully!\n",head->num);
    head=(head->next);
}

void display()
{
    if(c==0)
    {
    printf("STACK EMPTY!\n");
    return;
    }
	printf("STACK:\n");
	struct node *ptr=head;
	while(ptr!=NULL)
	{	
   		printf("%d\n",ptr->num);
    	ptr=ptr->next;
	}
}

void main()
{
    struct node *ptr;
    int m=0;
    int ch;
    while(m!=1)
    {
        ch=menu();
    switch (ch)
    {
        case 1:
        ptr=(struct node*)malloc(sizeof(struct node*));
        printf("Enter new element:");
        scanf("%d",&ptr->num);
        push(ptr);
        break;
        case 2:
        pop();
        break;
        case 3:
        printf("Count:%d\n",c);
        break;
        case 4:
        display();
        break;
        case 5:
        m=1;
        break;
        default:
        printf("Wrong input\n");
    }
    }
}
    