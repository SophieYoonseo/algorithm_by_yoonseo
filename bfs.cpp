#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void bfs(int start, vector<int> graph[], bool visited[])
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	
	while(!q.empty()){
      int temp = q.front();
      q.pop();
      cout<<temp+1<<" ";
      for(int i=0; i<graph[temp].size(); i++){
         if(visited[graph[temp][i]] == false){
            q.push(graph[temp][i]);
            visited[graph[temp][i]] = true;
         }
      }
   }
	
	
}

int main()
{
	int n, m;
	cin>>n;
	cin>>m;  //number of line
	
	vector<int> graph[n+1];
	bool visited[n+1];
	fill(visited, visited+n+1, false);
	
	int x,y;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	int start;
   	cin >> start;
   
  	for(int i=0; i<n; i++) 
    sort(graph[i].begin(), graph[i].end());

    bfs(start-1, graph, visited);

	return 0;
}
