#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e5;
int n,W;
int w[N+5],v[N+5];
int dp[M+5],inf=1e9+5;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for (int i=1;i<=M;i++) dp[i]=inf;
    for (int i=1;i<=n;i++) {
    	for (int V=M;V>=v[i];V--) {
    		dp[V]=min(dp[V],dp[V-v[i]]+w[i]);
    	}
    }
    for (int i=M;i>=0;i--) {
    	if (dp[i]<=W) {
    		cout<<i;
    		return 0;
    	}
    }
}