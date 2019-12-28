#include<bits/stdc++.h>
using namespace std;
int fibo[100];
int fibonocci(int n)
{
    if(fibo[n] != -1)
    {
        return fibo[n];
    }
    fibo[n]= fibonocci(n-1) + fibonocci(n-2);
    return fibo[n];
}

int main()
{
    int n,i,sum=0;
    memset(fibo,-1,100);
    fibo[0] = 0;
    fibo[1] = 1;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    cout<<endl<<fibonocci(n)<<endl;
    for(i=0;i<=n;i++)
    {
        sum+=fibo[i];
       cout<<fibo[i]<<" ";
    }
    cout<<endl<<sum;



}
