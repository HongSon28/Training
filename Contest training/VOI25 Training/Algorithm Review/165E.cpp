#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=22;
int n;
int a[N+5];
pair<int,int>dp[(1<<M)+5];
vector<int>msk[M+1];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		dp[a[i]].first=i;
	}
	for (int i=0;i<(1<<M);i++) {
		msk[__builtin_popcount(i)].push_back(i);
	}
	for (int i=1;i<M;i++) {
		for (auto mask:msk[i]) {
			//cout<<i<<' '<<mask<<' '<<dp[mask].first<<' '<<dp[mask].second<<endl;
			for (int j=0;j<M;j++) {
				if (!(mask>>j&1)) continue;
				int cur=(mask^(1<<j));
				//cout<<i<<' '<<mask<<' '<<j<<' '<<cur<<endl;
				pair<int,int>t=dp[cur];
				if (t.first==-1) continue;
				if (dp[mask].first==-1) {
					dp[mask].first=t.first;
					if (t.second!=-1) dp[mask].second=t.second;
				} else if (dp[mask].second==-1) {
					if (t.first!=dp[mask].first) dp[mask].second=t.first;
				} else break;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		int mask=0;
		for (int j=0;j<M;j++) {
			if (!(a[i]>>j&1)) mask|=(1<<j);
		}
		pair<int,int>t=dp[mask];
		if (t.first==-1) {
			cout<<-1<<' ';
			continue;
		}
		if (t.first!=i) cout<<a[t.first]<<' ';
		else if (t.second!=-1&&t.second!=i) cout<<a[t.second]<<' ';
		else cout<<-1<<' ';
	}
}
