#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int c=0;
int menu()
{
    printf("Menu:\n");
    printf("1. Insert operation on element in the linked list\n");
    printf("2. Display the linked list\n");
    printf("3. Update operation on element in the linked list\n");
    printf("4. Delete operation on element in the linked list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int n;
    scanf("%d",&n);
    return n;
}

struct node
{
	char name[15];
	int age;
	char gender[8];
	struct node *next;
}*head=NULL;
struct node *trav;
void insertst(struct node *ptr)
{
	ptr->next=head;
	head=ptr;c++;
    printf("Element added.\n");
}

void insertend(struct node *ptr)
{
	if(head==NULL)
	{
	head=ptr;
	ptr->next=NULL;
	return;
	}
	trav=head;
	while(1)
	{
	if(trav->next==NULL)
	{
		trav->next=ptr;
		ptr->next=NULL;c++;
    printf("Element added.\n");
    
		return;
	}
	else
	trav=trav->next;
	}
}
void insertpt(struct node *ptr, int pos)
{
    if (pos == 1)
    {
        insertst(ptr);
        return;
    }
    int i = 1;
    trav = head;
    while (i<pos-1 && trav!= NULL)
    {
        trav=trav->next;
        i++;
    }
    
    struct node *temp = trav->next;
    trav->next = ptr;
    ptr->next = temp;
    c++;
    printf("Element added.\n");
}

void updatebyval()
{
    int ch;
    printf("Which value you want to update?\n1. Name\t2. Age\t3. Gender\n");
    scanf("%d", &ch);
    char searchValue[15];
    printf("Enter the value to search for: ");
    scanf("%s", searchValue);
    trav = head;
    while (trav != NULL)
    {
        switch (ch)
        {
        case 1:
            if (strcmp(trav->name, searchValue) == 0)
            {
                printf("Enter the new name: ");
                scanf("%s", trav->name);
                printf("Node updated.\n");
                return; 
            }
            break;

        case 2:
            if (trav->age == atoi(searchValue))
            {
                printf("Enter the new age: ");
                scanf("%d", &trav->age);
                printf("Node updated.\n");
                return; 
            }
            break;

        case 3:
            if (strcmp(trav->gender, searchValue) == 0)
            {
                printf("Enter the new gender: ");
                scanf("%s", trav->gender);
                printf("Node updated.\n");
                return; 
            }
            break;

        default:
            printf("Invalid input!\n");
            return; 
        }

        trav = trav->next;
    }

    printf("Value not found in the linked list.\n");
}


void updatebypos(int pos)
{   
    int i = 1,ch;
    trav = head;
    while (i<pos)
    {
        trav=trav->next;
        i++;
    }
    printf("Which value you want to update?\n1.Name\t2.Age\t3.Gender\n");
    scanf("%d",&ch);
    char up[]="";int upag;
    if(ch==1)
    {
        printf("Enter the new name: ");scanf("%s",&up);
        strcpy(trav->name,up);printf("Value updated.");
    }
    else if(ch==2)
    {
        printf("Enter the new age: ");scanf("%d",&upag);
        trav->age=upag;printf("Value updated.");
    }
    else if(ch==3)
    {
        printf("Enter the new gender: ");scanf("%s",&up);
        strcpy(trav->gender,up);printf("Value updated.");
    }
    else
    printf("Invalid input!");
}
void delete(int pos)
{
    int i = 1;
    trav = head;
    if(pos==1)
    {
    head=trav->next;
    printf("Element removed.\n");
    c--;return;
    }
    while (i<pos-1)
    {
        trav=trav->next;
        i++;
    }
    trav->next = (trav->next)->next;
    printf("Element removed.\n");
    c--;
}
void display()
{
	printf("The values entered into linked list with address is :\n");
	struct node *ptr=head;
	while(ptr!=NULL)
	{	
		printf("\n");
   		printf("Address : %p\nName : %s\nAge : %d\nGender : %s\n",ptr,ptr->name,ptr->age,ptr->gender);
    	ptr=ptr->next;
	}
	printf("\nEND OF ELEMENTS\n");
}

void sc(int n)
{
	int pos;
	struct node *ptr;
    switch(n)
    {
        case 1:
        printf("Enter\n1 for insert at first or \n2 for insert at end position or \n3 for insert at a particular position\n:");
        scanf("%d",&n);
        ptr=(struct node*)malloc(sizeof(struct node*));
		printf("Enter name: ");
		scanf("%s",ptr->name);
		printf("Enter age: ");
		scanf("%d",&ptr->age);
		printf("Enter gender: ");
		scanf("%s",ptr->gender);
		if (n==1)
        insertst(ptr);
        else if (n==2)
        insertend(ptr);
        else if(n==3)
        {
		printf("Enter position to insert\n");
        scanf("%d",&pos);
        if (pos>c+1 || pos<1 )
        printf("Invalid position\n");
        else
        insertpt(ptr,pos);
        }
		break;
        case 2:
        display();
        break;
        case 3:
        printf("Enter 1.Update by value or 2.Update by position:");
        scanf("%d",&n);
        if (n==1)
        updatebyval();
        else if (n==2)
        {
        printf("Enter position to update\n");
        scanf("%d",&pos);
        if (pos>c+1 || pos<1 )
        printf("Invalid position\n");
        else
        updatebypos(pos);
        }
        break;
        case 4:
        printf("Enter position of element to delete: ");
        scanf("%d",&pos);
        if(c>=pos)
        delete(pos);
        else
        printf("Invalid position entered\n");
        break;
       
    }
}
void main()
{
    int n;
    do
    {
        n=menu();
        sc(n) ;
    } while (n!=5);
    printf("END");    
}
