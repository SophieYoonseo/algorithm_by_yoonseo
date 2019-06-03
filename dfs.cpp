#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]){
  	visited[start]= true;
   	cout<<start+1<<" ";

   	for(int i=0; i < graph[start].size(); i++){
      	int next = graph[start][i];
      	if(visited[next]==false) 
      	dfs(next, graph, visited);
   }
}

int main (){

   	int n;
   	int m; //number of line
   	cin >> n >> m;

   	vector<int> graph[n+1];
   	bool visited[n+1];
   	fill(visited, visited+n+1, false);
   
   	int x, y;  //line
   	for(int i=0; i<m; i++){
      	cin >> x >> y;

      	graph[x-1].push_back(y-1);
      	graph[y-1].push_back(x-1);
   	}

   	int start;
   	cin >> start;

   	for(int i=0; i<n; i++) 
   	sort(graph[i].begin(), graph[i].end());
   
   	dfs(start-1, graph, visited);

   	return 0;
}
