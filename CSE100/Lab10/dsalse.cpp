#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <stack>
#define infinity 9999
using namespace std;

using namespace std;

class Stronglyconnectedcomponent

{
int Vertex;
list<int> *adjacent;
void SCCfillID(int vertex, bool traveresd[], stack<int> &Stack);
void SSCDFS(int vertex, bool traveresd[],int node,int ar[]);
public:

Stronglyconnectedcomponent(int Vertex);

void connectededge(int vertex, int w);
void printSCCs(int node,int arr[]);

Stronglyconnectedcomponent getTranspose();

};
Stronglyconnectedcomponent::Stronglyconnectedcomponent(int Vertex)

{
this->Vertex = Vertex;
adjacent = new list<int>[Vertex];

}

void Stronglyconnectedcomponent::SSCDFS(int vertex, bool traveresd[],int node,int arr[])

{

traveresd[vertex] = true;

arr[vertex]=node;
list<int>::iterator i;

for (i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

if (!traveresd[*i])

SSCDFS(*i, traveresd,node,arr);

}

Stronglyconnectedcomponent Stronglyconnectedcomponent::getTranspose()

{

Stronglyconnectedcomponent g(Vertex);

for (int vertex = 0; vertex < Vertex; vertex++)

{
list<int>::iterator i;

for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

{

g.adjacent[*i].push_back(vertex);

}

}

return g;

}

void Stronglyconnectedcomponent::connectededge(int vertex, int w)

{

adjacent[vertex].push_back(w);

}
void Stronglyconnectedcomponent::SCCfillID(int vertex, bool traveresd[], stack<int> &Stack)

{

traveresd[vertex] = true;
list<int>::iterator i;

for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

if(!traveresd[*i])

SCCfillID(*i, traveresd, Stack);

Stack.push(vertex);

}


void Stronglyconnectedcomponent::printSCCs(int node,int arr[])

{

stack<int> Stack;
bool *traveresd = new bool[Vertex];

for(int i = 0; i < Vertex; i++)

traveresd[i] = false;

for(int i = 0; i < Vertex; i++)

if(traveresd[i] == false)

SCCfillID(i, traveresd, Stack);

Stronglyconnectedcomponent gr = getTranspose();

for(int i = 0; i < Vertex; i++)

traveresd[i] = false;
while (Stack.empty() == false)

{


int vertex = Stack.top();

Stack.pop();


if (traveresd[vertex] == false)

{

gr.SSCDFS(vertex, traveresd,vertex,arr);

int min=vertex;

for(int i=0;i<node;i++)

{

if(arr[i]==vertex)

{



if(min>i)

min=i;

}

}

for(int i=0;i<node;i++)

if(arr[i]==vertex)

arr[i]=min;

}

}

}

int main()

{

int node,edge;

cin>>node;

cin>>edge;


Stronglyconnectedcomponent g(node);

for(int i=0;i<edge;i++)

{

int u,w;

cin>>u>>w;

g.connectededge(u,w);

}

int arr[node];

for(int i=0;i<node;i++)

{

arr[i]=node+2;

}

g.printSCCs(node,arr);


for(int i=0;i<node;i++)

{

cout<<arr[i]<<endl;

}

return 0;

}