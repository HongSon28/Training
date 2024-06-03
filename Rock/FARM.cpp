#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k,p,q;
long long a[N+5],dp[N+5][N+5],res;
bool used[N+5];
void trace(int i,int j) {
	if (i==0||j==0) return;
	if (dp[i][j]==dp[i-1][j]) trace(i-1,j);
	else if (j==1) {
		if (dp[i][j]==a[i]) {
			used[i]=true;
			return;
		}
	} else {
		if (i-k>=1&&dp[i][j]==dp[i-k][j-1]+a[i]) {
			used[i]=true;
			trace(i-k,j-1);
		}	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>q>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=min((q+p-1)/p,n);
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<=min(i,cnt);j++) dp[i][j]=dp[i-1][j];
    	dp[i][1]=max(dp[i][1],a[i]);
    	if (i-k>=1) {
    		for (int j=2;j<=min(i,cnt);j++) dp[i][j]=max(dp[i][j],dp[i-k][j-1]+a[i]);
    	}
    }
    int mx=0,ps=0;
    for (int i=0;i<=cnt;i++) {
    	if (mx<dp[n][i]) {
    		mx=dp[n][i];
    		ps=i;
    	}
    }
    trace(n,ps);
    vector<long long>v;
    for (int i=1;i<=n;i++) if (used[i]) v.push_back(a[i]);
    sort(v.rbegin(),v.rend());
    for (auto x:v) {
    	int cur=min(p,q);
    	q-=cur;
    	res+=x*cur;
    }
    cout<<res;
}