#include<bits/stdc++.h>
using namespace std;

queue<int>q;
string color[1000]="white";
int d[10000],p[10000];

class Node
{
    public:
        int data;
        int weight;
        Node *Next;
    };

class datatyp
{
    public:
       Node *head= NULL;
};

void addEdge(datatyp a[],int src,int dest)
{
    Node *newnode = new Node();
    newnode->data = dest;
    newnode->Next=NULL;

    if(a[src].head == NULL)
        a[src].head=newnode;

    else
    {
      Node *temp = a[src].head;
      while(temp->Next != NULL)
        temp = temp->Next;
        temp->Next=newnode;

    }
}

void BFS(datatyp arr[],int s)
{
    q.push(s);
    color[s]="gray";
    d[s]=0;
    p[s]=0;
    while(!q.empty())
    {
        int parent;
        parent=q.front();
        q.pop();
        cout<<parent<<" ";

        Node *temp= arr[parent].head;
        while(temp != NULL)
        {
            if(color[temp->data] =="white")
            {
                q.push(temp->data);
                color[temp->data]= "gray";
                d[temp->data] =d[parent]+1;
                p[temp->data] = parent;
            }
            temp = temp->Next;
        }
        color[parent]="black";
    }
}



int main()
{
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
    BFS(arr,1);
    cout<<endl<<p[6];
 return 0;
}

/* input from input.txt file
7  //no of vertex
 
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
