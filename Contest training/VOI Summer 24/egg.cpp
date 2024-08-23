#include<bits/stdc++.h>
using namespace std;
const int N=1e3,M=1000;
long long e,n;
int lo=1,hi=100;
long long dp[M+5][N+5];
void solve() {
	for (int i=1;i<=N;i++) dp[1][i]=i;
	for (int i=2;i<=e;i++) {
		for (int d=1;d<=N;d++) {
			dp[i][d]=1+dp[i][d-1]+dp[i-1][d-1];
			if (i==e&&dp[i][d]>=n) {
				cout<<d;
				return;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>e>>n;
    if (e==1) {
    	cout<<n;
    	return 0;
    }
    solve();
}