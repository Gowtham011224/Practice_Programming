#include<stdio.h>
void mergesort(int arr[],int beg,int mid,int end){
    int i,j,k,n1,n2;
    n1=(mid-beg)+1;
    n2=end-mid;
    int arr1[n1],arr2[n2];
    for(i=0;i<n1;i++){
        arr1[i]=arr[beg+i];
    }
    for(j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=beg;
    while((i<n1)&&(j<n2)){
        if(arr1[i]<=arr2[j]){
        arr[k]=arr1[i];
        i++;
        k++;
        }
       else{
        arr[k]=arr2[j];
        j++;
        k++;
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void merge(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        merge( arr, beg, mid);
        merge(arr,mid+1,end);
        mergesort(arr,beg,mid,end);
    }
}

void display(int arr[],int n)
{
    printf("array contains:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void mergeSort()
{
    int n,i;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("before sorting\n");
    display(arr,n);
    merge(arr,0,n-1);
    printf("after sorting\n");
    display(arr,n);
}