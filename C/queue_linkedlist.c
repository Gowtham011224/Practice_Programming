#include<stdio.h>
#include<stdlib.h>
struct node
{
    int n;
    struct node *next;
}*head=NULL;
struct node *trav;
int c=0;
int menu()
{   
    int ch;
    printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Count of elements\n4.Display queue\n5.End\nChoice:");
    scanf("%d",&ch);
    return ch;
}
void Enqueue(struct node *ptr)
{
	if(head==NULL)
	{
	head=ptr;
	ptr->next=NULL;
    c++;
    printf("Element added to Queue Successfully!\n");
	return;
	}
	trav=head;
	while(1)
	{
	if(trav->next==NULL)
	{
		trav->next=ptr;
		ptr->next=NULL;c++;
    printf("Element added to Queue Successfully!\n");
   	return;
	}
	else
	trav=trav->next;
	}
}
void Dequeue()
{
    int e=head->n;
    head=head->next;
    c--;
    printf("Element(%d) Dequeued Successfully!\n",e);
    return;
}
void display()
{
    if(c==0)
    {
    printf("QUEUE EMPTY!\n");
    return;
    }
	printf("QUEUE:");
	struct node *ptr=head;
	while(ptr!=NULL)
	{	
   		printf("%d ",ptr->n);
    	ptr=ptr->next;
	}
    printf("\n");
    return;
}

void main()
{
    int m=1;
    struct node *ptr;
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
        printf("Enter number:");
        scanf("%d",&num);
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->n=num;
        Enqueue(ptr);
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
        Dequeue();
        break;
        case 3:
        printf("Count:%d\n",c);
        break;
        case 4:
        display();
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