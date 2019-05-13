#include <iostream>
#include <cstdlib>
#include<algorithm>
using namespace std;

int C[100][100];

int matrixPath(int n, int m)
{
   	int A[n][m];   
   	A[1][1]=C[1][1];
   
   	for(int i=2; i<=n; i++)
      	A[i][1]=C[i][1]+A[i-1][1];
   	for(int j=2; j<=m; j++)
      	A[1][j]=C[1][j]+A[1][j-1];
   	for(int i=2; i<=n; i++){
      	for(int j=2; j<=m; j++){
        	A[i][j] = C[i][j] + min(A[i-1][j], A[i][j-1]);
      	}
   	}
   	return A[n][m];
}

int main()
{
   	int n, m;   // size of map
   	cin >>n>>m;
    for(int i=1; i<=n; i++){
      	for(int j=1; j<=m; j++){
        	cin >> C[i][j];
      	}
   	}
   	cout<<matrixPath(n,m);
}
