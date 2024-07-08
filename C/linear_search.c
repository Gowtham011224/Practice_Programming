#include<stdio.h>
void main()
{
printf("Enter the size of the array\n");
int n;
scanf("%d",&n);
int i,arr[n];
for(i=0;i<n;i++)
{
printf("enter number:");
scanf("%d",&arr[i]);
}
printf("Enter the number to search in the array\n");
int num,f=0;
scanf("%d",&num);
for(i=0;i<n;i++)
if(num==arr[i])
{
f=1;
break;
}
if(f==1)
printf("The element is present in the array at index %d.\n",i);
else 
printf("The element is not present in the array.\n");
}
