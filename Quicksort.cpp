/*input value from quicksort.txt
10

52
23
45
68
88
42
23
44
6
14
*/

#include<bits/stdc++.h>
using namespace std;

class Quick_Sort
{
    public:
        int a[50];

 void quick_sort(int a[],int L,int R)
{
    int q;
    if(L<R)
    {
        q=Partition(a,L,R);
        quick_sort(a,L,q-1);
        quick_sort(a,q+1,R);
    }
}

    int Partition(int a[],int L,int R)
    {
        int x,i,j,temp;
        x=a[L];
        i=L;
        j=R+1;

        do
        {
            do
                i++;

            while(a[i]<x and i<=R);

            do
                j--;
            while(x<a[j]);

            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }while(i<j);

        a[L]=a[j];
        a[j]=x;

        return(j);
    }


};



int main()
{
    freopen("Quicksort.txt","r",stdin);

    Quick_Sort obj;

    int a[50],n,i;
      cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }


    obj.quick_sort(a,0,n-1);

    cout<<"\nArray after sorting: ";

    for(i=0;i<n;i++)
       {
       cout<<a[i]<<" ";
       }

    return 0;
}
