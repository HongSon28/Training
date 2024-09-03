#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
struct choice{
	int a,b;
	bool operator < (const choice &other) const {
		if (b>0&&other.b<0) return b>other.b;
		if (b<0&&other.b>0) return b>other.b;
		if (b>0&&other.b>0) return a<other.a;
		return a+b>=other.a+other.b;
	}
}x[N+5];
int n,s;
bool dp[N*4];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>x[i].a>>x[i].b;
    sort(x+1,x+1+n);
    dp[s+2*N]=true;
    int res=s;
    for (int i=1;i<=n;i++) {
    	if (x[i].b>=0) {
            for (int k=N;k>=-N;k--) {
                int last=k-x[i].b;
                if (dp[k+2*N]||!dp[last+2*N]) continue;
                if (last>=x[i].a) dp[k+2*N]=true;
                if (dp[k+2*N]) res=min(res,k);
            }
    	} else {
            for (int k=-N;k<=N;k++) {
                int last=k-x[i].b;
                if (dp[k+2*N]||!dp[last+2*N]) continue;
                if (last>=x[i].a) dp[k+2*N]=true;
                if (dp[k+2*N]) res=min(res,k);
            }
    	}
    }
    cout<<res;
}
