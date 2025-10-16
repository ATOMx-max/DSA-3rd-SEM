#include<stdio.h>
int max(int arr[],int n)
{
    int max_element=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_element)
        {
            max_element=arr[i];
        }
    }
    return max_element;
}
void Counting_short(int arr[],int n)
{
    int e_max=max(arr,n);
    int output[n];
    int count[e_max+1];
    for(int i=0;i<=e_max;i++)//set all to 0
    {
        count[i]=0;
    }
    //scan the input array and count the number of each element
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    //store the address in the cout
    //0 index unchange tharefore i=1
    for(int i=1;i<=e_max;i++)
    {
        count[i]+=count[i-1];
    }
    //shoring scan the input array from R to L
    for(int i=n-1;i>=0;i--)
    {
        int index=count[arr[i]]-1;
        count[arr[i]]--;
        output[index]=arr[i];
    }
    //copy the output array to input 
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={5,9,12,4,5,7,9,8,0,2,4,12,0,7};
    int t_element=sizeof(arr)/sizeof(arr[1]);
    //printf("%d",max(arr,t_element));
    printf("Arr is:");
    print(arr,t_element);
    Counting_short(arr,t_element);
    printf("Short order:");
    print(arr,t_element);

}