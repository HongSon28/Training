#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m,res;
string s,t;
int dp[N+5][N+5];
int mx[N+5][N+5];
vector<int>pos[27];
int nxt(int lim,char c) {
	auto it=lower_bound(pos[c-'a'].begin(),pos[c-'a'].end(),lim);
	if (it==pos[c-'a'].end()) return m+1;
	return *it;
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s>>t;
	n=s.size(),m=t.size();
	s=' '+s,t=' '+t;
	for (int i=1;i<=m;i++) pos[t[i]-'a'].push_back(i);
	for (int k=1;k<=n;k++) {
		for (int i=k;i<=n;i++) {
			dp[i][k]=nxt(mx[i-1][k-1]+1,s[i]);
			//cout<<i<<' '<<k<<' '<<dp[i][k]<<endl;
			mx[i][k]=max(mx[i-1][k],dp[i][k]);
			if (dp[i][k]>m) {
				cout<<k;
				return 0;
			}
		}
	}
	cout<<-1;
}