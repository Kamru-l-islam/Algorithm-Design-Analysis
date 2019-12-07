#include<bits/stdc++.h>
using namespace std;

string color[10000] = "white";
int Time = 0;
int d[10000],f[10000];

class Node
{
    public:
        int target;
        int weight;
        Node *next;
};

class datatyp
{
    public:
        Node *head = NULL;
};

void addEdge(datatyp arr[],int src,int dest)
{
    Node *newNode = new Node();
    newNode->target = dest;
    newNode->next = NULL;

    if( arr[src].head == NULL)
        arr[src].head = newNode;
    else
    {
        Node *temp = arr[src].head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void DFS_Visit(datatyp arr[],int s,int parent[])
{
    color[s] = "Gray";
    Time =Time+1;
    d[s] = Time;
    Node *temp = arr[s].head;
    cout<<s<< " ";

    while( temp!=NULL)
    {
        int child = temp->target;
        if( color[child] == "white")
        {
            parent[child] = s;
            DFS_Visit(arr,child,parent);
        }
        temp = temp->next;
    }
    color[s] = "Black";
    Time = Time+1;
    f[s] = Time;
}

void DFS(datatyp arr[],int parent[],int v){
    for(int i=1; i<=v; i++)
    {
        if(color[i] == "white")
            DFS_Visit(arr,i,parent);
    }
}
int main()
{
    int prev[10000] = {0};
    freopen("input.txt","r",stdin);
    int v;
    cin>>v;
    datatyp arr[v+1];

    int m,n;
    while(cin>>m>>n)
    {
        addEdge(arr,m,n);
        addEdge(arr,n,m);
    }

    DFS(arr,prev,v);
    cout<<endl<<d[7]<<" "<<f[7]<<" "<<prev[7]<<endl; //starting time d[] and Finishing time F[]
}
/*input from input.txt file

7 //no of vertex
 
1 2 //Edges
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
