#include<stdio.h>
void disp(int arr[],int n){
    printf("array contains\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insert(int arr[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while((j>=0)&&(temp<=arr[j])){
                arr[j+1]=arr[j];
                j--;
        }
        arr[j+1]=temp;

    }
    disp(arr,n);
}


void main()
{
    int i,n;
    printf("Enter no of elements: " );
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);

    }
    printf("before sorting\n");
    disp(arr,n);
    printf("after sorting\n");
    insert(arr,n);
}
