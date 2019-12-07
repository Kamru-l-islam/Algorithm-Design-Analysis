#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int destination;
        int weight;
        Node *Next ;
};

class graphsion
{
    public:
        Node *head=NULL;
};

void AddEdge(graphsion arr[],int src,int dest,int w)
{
    Node *newnode;
    newnode = new Node();
    newnode->destination = dest;
    newnode->weight= w;
    newnode->Next = NULL;

    if(arr[src].head == NULL)
        arr[src].head = newnode;

    else{
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
            cout<<" "<<arrlist[i].head->destination<<"="<<arrlist[i].head->weight;
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

    int m,n,w;

    while(cin>>m>>n>>w)
    {
        AddEdge(a,m,n,w);
        AddEdge(a,n,m,w);

    }
    display(a,v);

 return 0;
}

/*
input from input.txt file
7 //vertex size

1 2 5 //edge & weight
1 3 6
2 3 12
4 5 8
5 6 9
5 3 6
6 2 23
6 4 2
3 7 6
5 7 3
*/
