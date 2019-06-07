#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]){
  	visited[start]= true;
   	cout<<start<<" ";

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
   	fill(visited, visited+n+1, false);  //initialize the array to false
   
   	int x, y;  //line
   	for(int i=0; i<m; i++){
      	cin >> x >> y;
      	graph[x].push_back(y);
      	graph[y].push_back(x);
   	}

   	int start;
   	cin >> start;

   	for(int i=0; i<n; i++) 
   	sort(graph[i].begin(), graph[i].end());
   
   	dfs(start, graph, visited);

   	return 0;
}
