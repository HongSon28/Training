#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,m;
string s,t;
int dp[N+5][N+5],inf=1e9,res=inf;
vector<int>pos[30];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>s>>t;
    s=' '+s,t=' '+t;
    for (int i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
    for (int i=0;i<=n;i++)
    	for (int j=0;j<=m;j++)
    		dp[i][j]=inf;
    for (int i=1;i<=n;i++) if (s[i]==t[1]) dp[i][1]=0;
    for (int i=1;i<=n;i++) {
    	for (auto t:pos[s[i]-'a']) {
    		if (t==i) continue;
    		dp[t][1]=min(dp[t][1],dp[i][1]+abs(t-i));
    	}
    }
    for (int j=2;j<=m;j++) {
    	for (int i=1;i<=n;i++) {
    		if (i+1<=n&&s[i+1]==t[j]) dp[i+1][j]=min(dp[i+1][j],dp[i][j-1]+1);
    		if (i-1>=1&&s[i-1]==t[j]) dp[i-1][j]=min(dp[i-1][j],dp[i][j-1]+1);
    	}	
    	for (int i=1;i<=n;i++) {
    		for (auto t:pos[s[i]-'a']) {
    			if (t==i) continue;
    			dp[t][j]=min(dp[t][j],dp[i][j]+abs(t-i));
    		}
    	}
    }
    for (int i=1;i<=n;i++) res=min(res,dp[i][m]);
    if (res==inf) cout<<-1;
    else cout<<res;
}