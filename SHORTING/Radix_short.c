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
void Counting_short(int arr[],int n,int pow10)
{
    //int e_max=max(arr,n);
    int output[n];
    int count[10];
    for(int i=0;i<10;i++)//set all to 0
    {
        count[i]=0;
    }
    //scan the input array and count the number of each element
    for(int i=0;i<n;i++)
    {
        int index=(arr[i]/pow10)%10;
        count[index]++;
    }
    //store the address in the cout
    //0 index unchange tharefore i=1
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    //shoring scan the input array from R to L
    for(int i=n-1;i>=0;i--)
    {
        int index=count[(arr[i]/pow10)%10]-1;
        count[(arr[i]/pow10)%10]--;//update
        output[index]=arr[i];
    }
    //copy the output array to input 
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radix_short(int arr[],int n)
{
    int e_max=max(arr,n);
    int pow10=1;
    while(e_max!=0)
    {
        //shoting according to digit star from last digit
        Counting_short(arr,n,pow10);
        pow10*=10;
        e_max/=10;
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
    int arr[]={94,257,21,8,400,327,76,6,48,99,64,30};
    int t_element=sizeof(arr)/sizeof(arr[1]);
    //printf("%d",max(arr,t_element));
    printf("Arr is:");
    print(arr,t_element);
    radix_short(arr,t_element);
    printf("Short order:");
    print(arr,t_element);

}