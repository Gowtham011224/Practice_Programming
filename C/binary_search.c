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
int ll=0,ul=n-1,mid;
while(ll<=ul)
{
mid=(ll+ul)/2;
if(arr[mid]==num)
{
f=1;
break;
}
else if(num<arr[mid])
ul=mid-1;
else if(num>arr[mid])
ll=mid+1;
}
if(f==1)
printf("The element is present in the array at index %d.\n",mid);
else 
printf("The element is not present in the array.\n");
}
