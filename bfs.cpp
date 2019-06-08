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
      	int temp = q.front();   //the first element of queue
      	q.pop();              //take off the first element
      	cout<<temp<<" ";
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
	fill(visited, visited+n+1, false);  //initialize the array to false
	
	int x,y;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int start;
   	cin >> start;
   
  	for(int i=0; i<n; i++) 
    	sort(graph[i].begin(), graph[i].end());

    bfs(start, graph, visited);

	return 0;
}
