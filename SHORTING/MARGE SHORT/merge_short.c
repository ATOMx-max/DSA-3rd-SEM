//in a single array thare are two shorted part so we nedd to make it comppletly shorted
#include<stdio.h>
void m_merge(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int c[100];
    while(i<=mid&&j<=high)
    {
        if(A[i]<A[j])
        {
            c[k++]=A[i++];
        }
        else
        {
            c[k++]=A[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=A[i++];
    }
    while(j<=high)
    {
        c[k++]=A[j++];
    }
    for(int i=low;i<=high;i++)
    {
        A[i]=c[i];
    }
}
void merge_short(int arr[],int low,int high)
{
    int mid=(high+low)/2;
    //divide and concure
    //if high=low single node thats why
    if(low<high)
    {
        //s1
        merge_short(arr,low,mid);
        //s2
        merge_short(arr,mid+1,high);
        m_merge(arr,low,mid,high);
    }

}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main()
{
    int A[]={21,90,42,30,9,27,26,1};
    int e_A=sizeof(A)/sizeof(A[1]);
    int high=7,low=0;
    merge_short(A,low,high);
    display(A,e_A);
    return 0;
}