#include<bits/stdc++.h>
using namespace std;
const int N=100;
int f,v;
int a[N+5][N+5];
int dp[N+5][N+5],inf=1e9,res=-inf,pos[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>f>>v;
	for (int i=1;i<=f;i++) 
		for (int j=1;j<=v;j++)
			cin>>a[i][j];
	for (int i=1;i<=f;i++) {
		for (int j=i;j<=v;j++) {
			dp[i][j]=-inf;
			for (int k=j-1;k>=0;k--) {
				if (dp[i][j]<dp[i-1][k]+a[i][j]) {
					dp[i][j]=dp[i-1][k]+a[i][j];
				}
			}
			if (i==f){
				if (res<dp[i][j]) {
					res=dp[i][j];
					pos[i]=j;
				}
			}
		}
	}
	for (int i=f-1;i>=1;i--) {
		for (int j=pos[i+1]-1;j>=0;j--) {
			if (dp[i][j]+a[i+1][pos[i+1]]==dp[i+1][pos[i+1]]) {
				pos[i]=j;
				break;
			}
		}
	}
	cout<<res<<endl;
	for (int i=1;i<=f;i++) cout<<pos[i]<<' ';
}