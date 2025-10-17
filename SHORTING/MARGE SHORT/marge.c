//when two shorted array is given and ned to from 1 shorted array
#include<stdio.h>
void merge(int A[],int n,int B[],int m,int c[])
{
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(A[i]<B[j])
        {
            c[k++]=A[i++];
        }
        else
        {
            c[k++]=B[j++];
        }
    }
    while(i<n)
    {
        c[k++]=A[i++];
    }
    while(j<m)
    {
        c[k++]=B[j++];
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
    int A[]={5,7,9,12,15,20,25,30};
    int B[]={2,3,6,8,10,11};
    int e_A=sizeof(A)/sizeof(A[1]);
    int e_B=sizeof(B)/sizeof(B[1]);
    int o=e_A+e_B;
    int output[o];
    merge(A,e_A,B,e_B,output);
    display(output,o);
    return 0;
}