#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int destination;
        Node *Next ;
};

class graphsion
{
    public:
        Node *head=NULL;
};

void AddEdge(graphsion arr[],int src,int dest)
{
    Node *newnode = new Node();
    newnode->destination = dest;
    newnode->Next = NULL;

    if(arr[src].head == NULL)
        arr[src].head = newnode;

    else
    {
        Node *temp =arr[src].head;

            while(temp->Next != NULL)
                temp = temp->Next;
                temp->Next = newnode;
    }

}

void display(graphsion arrlist[],int v)
{
    int i;
    for(i=0;i<v;i++)
    {
        cout<<"\n adjacency list of vertex-"<<i<<"->";

        while(arrlist[i].head != NULL)
        {
            cout<<" "<<arrlist[i].head->destination;
            arrlist[i].head = arrlist[i].head->Next;
        }
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    int i,v;
    cin>>v;
    graphsion a[v+1];
    /*for( i=0;i<=v;i++) if don't increase v then using this loop
    a[i].head=NULL;*/

    int m,n;

    while(cin>>m>>n)
    {
        AddEdge(a,m,n);
        AddEdge(a,n,m);

    }
    display(a,v);

 return 0;
}

/*
input from input.txt file
7 //vertex size

1 2  //edge & weight
1 3 
2 3 
4 5 
5 6 
5 3 
6 2 
6 4 
3 7 
5 7 
*/
