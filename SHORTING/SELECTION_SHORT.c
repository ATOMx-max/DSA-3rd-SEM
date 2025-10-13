#include<stdio.h>
#include<stdlib.h>
void inserction_short(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<=n-1;i++)
    {   
        key=arr[i];
        j=i-1;
        while(j>=0&&key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

void selection_short(int arr[],int n)
{
    
    int j,i,index;
    for(i=0;i<=n-2;i++)
    {
        int index=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(arr[index]>arr[j])
            {
                index=j;
            }
        }
        int temp=arr[index];
        arr[index]=arr[i];
        arr[i]=temp;
    }
}
void boble_short(int arr[],int n)
{
    int i,j,flag;
    for(j=0;j<=n-2;j++)
    {
        flag=0;
        for(i=j;i<=n-2-j;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                 //swap
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
                flag=1;
            }
        }
        if(flag==0){break;}
    }
}
int main()
{
    int arr[]={30,50,20,10,60,40,88};
    printf("BEFORE:\n");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%d\t",arr[i]);
    }
    selection_short(arr,6);
    printf("\nSELECTION SHORT:\n");
    printf("AFTER:\n");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n");
    
    boble_short(arr,6);
    printf("\nBUBLE SHORT:\n");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%d\t",arr[i]);
    }
    inserction_short(arr,6);
    printf("\nInserction short:\n");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;

}