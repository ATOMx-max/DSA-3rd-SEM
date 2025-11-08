#include<stdio.h>
//with the immagenaction of tree we done it for array
//meain tree first convert to array;
void swap(int arr[],int n,int i)
{
    int temp=arr[1];
    arr[1]=arr[i];
    arr[i]=temp;
}
void heap_adjust(int arr[],int i,int n)
{
    int carry=arr[i];
    int j=2*i;//point to left child of ith posiction
    while(j<=n)
    {
        if(j<n && arr[j]<arr[j+1])
        {
            j++;
        }
        if(carry>arr[j]) break;
        arr[j/2]=arr[j];
        j=j*2;
    
    }
    arr[j/2]=carry;//last carry element assined
}
void makeHeap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--) 
    {
        heap_adjust(arr,i,n);
    }

}
void display(int arr[],int n)
{
    for(int i=1;i<=n;i++)//we voide the 0 index
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void heap_Short(int arr[],int n)
{
    makeHeap(arr,n);
    for(int i=n;i>=2;i--)//start from 1 so n-1 and 1 element is shorted so n-1-1=n-2
    {
        swap(arr,n,i);
        heap_adjust(arr,1,i-1);//last is alrady shorted
    }
}
int main()
{
    int arr[6] = {0, 20, 65, 48, 19, 14}; // index 0 unused
    int n = 5;
    printf("Original array:\n");
    display(arr, n);

    makeHeap(arr,n);
    printf("Heap Array:\n");
    display(arr,n);


    int arr2[6] = {0, 20, 65, 48, 19, 14}; // index 0 unused
    int k = 5;
    printf("Original array:\n");
    display(arr2, k);
    heap_Short(arr2, k);
    printf("Sorted array:\n");
    display(arr2, k);

    return 0;

}