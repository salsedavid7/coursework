#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
   int src, dest, weight;
};

struct Graph {
   int numVertices, numEdges;
   struct Edge* edge;
};

struct Graph* makeGraph(int numVertices, int numEdges) {
   struct Graph* graph = new Graph;
   graph -> numVertices = numVertices;
   graph -> numEdges = numEdges;
   graph -> edge = new Edge[numEdges];
   return graph;
}

void printArr(int d[], int n) {
   for (int i = 0; i < n; ++i) {
       if(d[i] == INT_MAX)
           printf("INFINITY\n");
       else
           printf("%d\n", d[i]);
   }
}
void BellmanFord(struct Graph* graph, int src) {
   int numVertices = graph -> numVertices;
   int numEdges = graph -> numEdges;
   int d[numVertices];

   for(int i = 0; i < numVertices; i++){
   d[i] = INT_MAX;
   d[src] = 0;
   }

   for (int i = 1; i <= numVertices - 1; i++) {
       for (int j = 0; j < numEdges; j++) {
           int a = graph -> edge[j].src;
           int b = graph -> edge[j].dest;
           int weight = graph -> edge[j].weight;
           if (d[a] != INT_MAX && d[a] + weight < d[b])
           d[b] = d[a] + weight;
       }
   }

   for (int i = 0; i < numEdges; i++) {
       int a = graph -> edge[i].src;
       int b = graph -> edge[i].dest;
       int weight = graph -> edge[i].weight;
       if (d[a] != INT_MAX && d[a] + weight < d[b]) {
           cout << "FALSE\n";
           return;
       }
   }
   cout << "TRUE\n";
   printArr(d, numVertices);
}

int main() {
   int numVertices;
   int numEdges;
   cin >> numVertices >> numEdges;
   int a, b, c;
   struct Graph* graph = makeGraph(numVertices, numEdges);
   for(int i = 0; i < numEdges; i++) {
       cin >> a >> b >> c;
       graph -> edge[i].src = a;
       graph -> edge[i].dest = b;
       graph -> edge[i].weight = c;
   }
   BellmanFord(graph, 0);
}