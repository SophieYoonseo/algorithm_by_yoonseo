#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#define MAX 987654321  //infinite  

using namespace std;
vector<vector<pair<int, int> > > adj;
int n, m, start, dest;
typedef pair<int, int> node;

struct cmp {
    bool operator()(node x, node y) {
        return x.second > y.second;
    }
};

void dijkstra(int x, int dest) {
    priority_queue<node, vector<node>, cmp> pq;
    vector<int> dist(n+1,MAX); 
   	dist[x] = 0;
    vector<int> prev(n+1,0);
    pq.push(make_pair(x,0));
    for(int i=1; i<=n;i++){
        if(i!=x) pq.push(make_pair(i,MAX));
    }
    
	while(!pq.empty()){
        int u = pq.top().first;
        int d = pq.top().second; 
      	pq.pop();
      
        if(d > dist[u]) continue;
        
        for(int i = 0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(v,dist[v]));
            }
        }       
    }
    
    for(int i=1; i<=n; i++) 
   		cout<<prev[i]<<" ";
   
    if(dist[dest]==MAX)
    	cout<<"Impossible";
    else
    	cout<<dist[dest];
    
}

int main() {
    cin>>n>>m;
    adj.resize(n + 1);
    
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
    }
    cin>>start>>dest;
    dijkstra(start, dest);
    
    return 0;
}
