#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,res;
char c[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			cin>>c[i][j];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (c[i][j]=='*'&&c[i-1][j]!='*'&&c[i][j-1]!='*') res++; 
		}
	}
	cout<<res;
}