//in a single array thare are two shorted part so we nedd to make it comppletly shorted
#include<stdio.h>
void m_merge(int A[],int n,int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int c[n];
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
    int A[]={12,15,20,25,9,16,35,40};
    int e_A=sizeof(A)/sizeof(A[1]);
    int high=7,low=0;
    int mid=(high+low)/2;
    m_merge(A,e_A,low,mid,high);
    display(A,e_A);
    return 0;
}