#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>

using namespace std;

string str1;
string str2;

int LCSsize(int m, int n)
{
	int C[m+1][n+1];
	for(int i=1; i<=m; i++)
	{
		C[i][0] = 0;
	}
	for(int j=1; j<=n; j++)
	{
		C[0][j] = 0;		
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(str1[i-1]==str2[j-1])
			{
				C[i][j]=C[i-1][j-1]+1;
			} 
			else
			{
				C[i][j]=max(C[i-1][j], C[i][j-1]);
			} 
		}
	}
	return C[m][n];
}

int main()
{
	cin>>str1>>str2;
	
	int len1, len2;
	len1=str1.length();
	len2=str2.length();

   	cout<<LCSsize(len1, len2);
}
