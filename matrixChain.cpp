#include<iostream>

using namespace std;

int m[100][2];
int dp[100][100];

int matrixChain(int n)
{
	for(int i=1; i<n; i++)
		dp[i][i+1] = m[i][0] * m[i][1] * m[i+1][1];
		
	for(int r=2; r<=n; r++){
		for(int i=1; i<=n-r; i++){
			int j = i+r;
			for(int k=i; k<j; k++){
				int res = dp[i][k] + dp[k+1][j] + m[i][0] * m[k][1] * m[j][1];
				if(!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
			}
		}
	}
	return dp[1][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, mul(0);
	cin>>n;
	
	for(int i=1; i<=n; i++)
		cin>>m[i][0]>>m[i][1];
		
	mul = matrixChain(n);
	
	cout<<mul<<"\n";
	
	return 0;
}
