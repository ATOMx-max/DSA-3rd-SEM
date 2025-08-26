//*************TIME VALUE OF MONEY ECO********************
#include<iostream>
#include<math.h>
#include<cctype>
#include<iomanip>
using namespace std;
//global variable
double i,p,f,a;
int n;
decltype(i)amount;
//function prototype
void SPCA();
void SPPWA();
void EPSCA();
void EPSSF();
void EPSPWA();
void EPSCRA();
int main()
{
    int ip;
    do{
        cout<<"1)Single payment compound amount(F)"<<endl;
        cout<<"2)Single payment present worth amount(P)"<<endl;
        cout<<"3)Equal paymnet series compund amount(F)"<<endl;
        cout<<"4)Sinking fund(A)"<<endl;
        cout<<"5)Equivalent payment seris present worth Amount(P)"<<endl;
        cout<<"6)Equivalent payment seris capital recovery amount(A)"<<endl;
        cout<<"7)Exite"<<endl<<"Enter:";
        cin>>ip;
        if (ip>0 && ip<7)
        {
            cout<<"Enter Interest in %:";
            cin>>i;
            i=i/100;
            //cout<<i<<"%"<<endl;
            cout<<"Enter Time Period in year:";
            cin>>n;
            //cout<<n;
            switch(ip)
            {
                case 1:{
                    SPCA();
                    break;
                }
                case 2:
                {
                    SPPWA();
                    break;
                }
                case 3:
                {
                    EPSCA();
                    break;
                }
                case 4:
                {
                    EPSSF();
                    break;
                }
                case 5:
                {
                    EPSPWA();
                    break;
                }
                case 6:
                {
                    EPSCRA();
                    break;
                }
                default:{
                    cout<<"Enter value in between (1 to 7)";
                }
            }
        }
    }
    //while (ip!=7);
    while(ip!=7);
    cout<<"Thnak you";
    return 0;
}

void SPCA()
{
    cout<<"Enter the Principal amount(P):";
    cin>>p;
    f=p*pow((1+i),n);
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Principal Amount(P):"<<p<<endl<<"Interest(I):"<<i<<endl<<"Time period in Year(N):"<<n<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Single payment Compound Amount(F):"<<f<<endl;
    cout<<endl;
}
void SPPWA()
{
    cout<<"Enter the Future amount (F):";
    cin>>f;
    p=f/pow((1+i),n);
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Single payment Compound Amount(F):"<<f<<endl<<"Interest(I):"<<i<<endl<<"Time period in Year(N):"<<n<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The single payment present worth amount(P):"<<p<<endl;
    cout<<endl;
}
void EPSCA()
{
    cout<<"Enter the Sinking Fund:";
    cin>>a;
    f=a*((pow((1+i),n)-1)/i);
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Sinking Fund(A):"<<a<<endl<<"Interest(I):"<<i<<endl<<"Time period in Year(N):"<<n<<endl;
    cout<<fixed<<setprecision(2);//format the output
    cout<<"Equal payment seris Compound amount(F)"<<f<<endl;
    cout<<endl;
}
void EPSSF()
{
    cout<<"Enter the Equivalent future amount(F):";
    cin>>f;
    a=f*i/(pow((1+i),n)-1);
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Equal payment seris Compound amount(F):"<<f<<endl<<"Interest:"<<i<<endl<<"Time period in Year:"<<n<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Sinking Fund(A):"<<a<<endl;
    cout<<endl;
}
void EPSPWA()
{
    cout<<"Enter the Annual Payment(A):";
    cin>>a;
    
    //p=a*(pow((1+i),n)-1/(i*pow((1+i),n)));
    p = a * ((1 - pow(1+i, -n)) / i);
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Sinking Fund (A):"<<a<<endl<<"Interest(I):"<<i<<endl<<"Time period in Year(N):"<<n<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Equivalent Payment Seris present worth amount(P):"<<p<<endl;
    cout<<endl;
}
void EPSCRA()
{
    cout<<"Enter the Principal amount(P):";
    cin>>p;
    a=p*((i*pow((1+i),n))/(pow((1+i),n)-1));
    cout<<endl;
    cout<<"****************OUTPUT******************"<<endl;
    cout<<"Equivalent Payment Series Capital Recovery Amount (A):"<<a<<endl<<"Interest(I):"<<i<<endl<<"Time period in Year(N):"<<n<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Recovery Sinking Amount(A):"<<a<<endl;
    cout<<endl;
}