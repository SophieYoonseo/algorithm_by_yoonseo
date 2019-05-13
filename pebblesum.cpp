#include<iostream>
#include<algorithm>

using namespace std;

int w[4][100];

int pebble(int n)
{
	int peb[5][n+1];
	int Max=0;
	for(int i=1; i<=n; i++)
		w[4][i] = w[1][i]+w[3][i];
	for(int p=1; p<=4; p++)
		peb[p][1] = w[p][1];
	for(int i=2; i<=n; i++){
		for(int p=1; p<=4; p++){
			if(p==1)
				peb[p][i]=max(peb[2][i-1], peb[3][i-1])+w[p][i];
			else if(p==2){
				Max = max(peb[1][i-1], peb[3][i-1]);
				peb[p][i]=max(Max, peb[4][i-1])+w[p][i];
			}
			else if(p==3)
				peb[p][i]=max(peb[1][i-1], peb[2][i-1])+w[p][i];
			else if(p==4)
				peb[p][i]=peb[2][i-1]+w[p][i];
		}
	}
	
	Max=max(max(peb[1][n], peb[2][n]), peb[3][n]);
	Max=max(Max, peb[4][n]);

	return Max;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1; i<4; i++){
		for(int j=1; j<=m; j++)
		cin>>w[i][j];
	}
	
	cout<<pebble(m);
}
