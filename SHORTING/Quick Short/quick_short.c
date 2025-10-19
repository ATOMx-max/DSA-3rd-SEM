#include<stdio.h>
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void display(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int partiction(int arr[],int low,int high)
{
    int i=low-1;
    int j;
    int privo=arr[high];
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<privo)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return i+1;
}
void quick_short(int arr[],int low,int high)
{
    if(low<high)
    {
        int j=partiction(arr,low,high);
        //for partiction 1
        quick_short(arr,low,j-1);
        //for partiction 2
        quick_short(arr,j+1,high);
    }
}

int main()
{
    int arr[]={60,30,70,40,10,90,80,20,50};
    int n=sizeof(arr)/sizeof(arr[1]);
    int high=n-1;
    int low=0;
    /*
    printf("BEFORE:\n");
    display(arr,n);
    printf("AFTER\n");
    swap(arr,0,1);
    display(arr,n);*/
    //partiction(arr,low,high);

    printf("BEFORE:\n");
    display(arr,n);
    quick_short(arr,low,high);
    printf("AFTER:\n");
    display(arr,n);
    return 0;
}