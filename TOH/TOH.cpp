#include<iostream>
using namespace std;

auto c=0;//global counter

//prototype
void TOH(int ,char ,char ,char);
int main()
{
    int disk;
    cout<<"Enter number of Disk:";
    cin>>disk;
    // S = source, A = auxiliary, D = destination
    TOH(disk,'S','A','D');
}
// function definaction
void TOH(int n,char s,char a,char d)
{
    if(n==1)
    {
        c++;
        cout<<"Move no:"<<c<<" Disk "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    TOH(n-1,s,d,a);
    c++;
    cout<<"Move no:"<<c<<" Disk "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(n-1,a,s,d);
}

