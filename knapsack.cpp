
#include<bits/stdc++.h>
using namespace std;
double p[] = {30,280,180,80};
double w[] = {10,40,20,10};
double x[] = {0.0};
//double p[100],w[100],x[100];

void knapsack(int m,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(p[i]/w[i] > p[j]/w[j])
            {
                swap(p[i],p[j]);
                swap(w[i],w[j]);
            }

        }
    }
    int u = m;

    for(i=1;i<=n;i++)
    {
        if(w[i]>u) break;

        x[i]=1.0;
        u=u-w[i];
    }
    if(i<=n)
        x[i]= u/w[i];
}

void display(int n)
{
    int i;
    double sum=0.0;
    for(i=1;i<=n;i++)
    {
        sum +=x[i]*p[i];
    }
    cout<<"Profit:"<<sum;
}

int main()
{
    //freopen("input2.txt","r",stdin);
    int n,u;
    cout<<"Enter the array size:"<<endl;
    cin>>n;
    cout<<"contain size:"<<endl;
    cin>>u;
  /*  for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }

        for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
*/
    knapsack(u,n);

    display(n);
    return 0;
}

