#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

void addEdge(vector <pair<int, int> > graph[], int u, int v, int w) {
   graph[u].push_back(make_pair(v, w));
   graph[v].push_back(make_pair(u, w));
}

void primMST(vector<pair<int,int> > adj[], int V) {
   priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
   int src = 0;
   vector<int> dist(V, INF);
   vector<int> parent(V, -1);
   vector<bool> inclMST(V, false);
   pq.push(make_pair(0, src));
   dist[src] = 0;
   while (!pq.empty()) {
       int u = pq.top().second;
       pq.pop();
       inclMST[u] = true;
       for (auto x : adj[u]) {
           int v = x.first;
           int weight = x.second;
           if (inclMST[v] == false && dist[v] > weight) {
               dist[v] = weight;
               pq.push(make_pair(dist[v], v));
               parent[v] = u;
           }
       }
   }

   for (int i = 1; i < V; ++i)
       printf("%d\n", parent[i]);
}

int main() {
    int V, E, u, v, w;
    cin >> V;
    vector<pair<int, int> > graph[V];
    cin >> E;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        addEdge(graph,u,v,w);
    }
   primMST(graph, V);
   return 0;
}
