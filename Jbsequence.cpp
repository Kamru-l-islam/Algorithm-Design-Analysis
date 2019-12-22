/*input from file
6
30 4
20 2
60 2
30 2
10 1
80 4
*/

#include<bits/stdc++.h>
using namespace std;
int p[10],j[10],d[10];

int Jbsequence(int d[],int j[],int m,int index[])
{
    int i,r,k;

    for(i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(p[j] < p[j+1])
            {
                swap(p[j],p[j+1]);
                swap(d[j],d[j+1]);
                swap(index[j],index[j+1]);
            }
        }
    }

    d[0]= 0;
    j[0]=0;
    j[1] = 1;
    k=1;
    for(i=2;i<=m;i++)
    {
        r=k;
        while(d[j[r]] >d[i] and d[j[r]] != r)
        {
            r=r-1;
        }

        if(d[j[r]]<= d[i] and d[i]>r)
        {
            int l;
            for(l=k;l>=r+1;l--)
                j[l+1] = j[l];

            j[r+1] = i;
            k = k+1;
        }
    }

    return k;
}
void display(int n,int result,int index[])
{
    int sum=0;
    cout<<"After sorting:\n";
    for(int i=1;i<=n; i++)
    {
        cout<<p[i]<<" "<<d[i];
        cout<<endl;
    }


    for(int i=1;i<=result; i++)
    {
        // cout<<j[i]<<" ";
        sum+=p[i];
        cout<<"Index: "<<index[i]<<"\t profit: "<<p[i]<<"\t deadlin:"<<d[i];
        cout<<"\t Solution: "<<j[i]<<"\ttotal_profit: "<<sum<<endl;

    }
     cout<<"\nMaximum profit:"<<sum<<endl;
}

int main()
{
    freopen("inputjb.txt","r",stdin);
    int n,i;
    cin>>n;
   int index[10];

    for(i=1; i<=n; i++)
    {

        cin>>p[i];
        cin>>d[i];
        index[i]=i;
    }

   int R = Jbsequence(d,j,n,index);
    display(n,R,index);
return 0;
}
