#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e6;
int n,x;
int c[N+5];
int dp[M+5];
int mod=1e9+7;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>c[i];
    dp[0]=1;
    for (int s=1;s<=x;s++) {
    	for (int i=1;i<=n;i++) if (s>=c[i]) add(dp[s],dp[s-c[i]]);
    }
    cout<<dp[x];
}