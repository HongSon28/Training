#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long dp[N+5][6],res,mod=1e9+7;
pair<int,int>p[40];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=q;i++) {
    	string s,t;
    	cin>>s>>t;
    	p[i]={s[0]-'a',t[0]-'a'};
    }
    dp[1][0]=1;
    for (int i=2;i<=n;i++) {
    	for (int j=1;j<=q;j++) {
    		dp[i][p[j].first]+=dp[i-1][p[j].second];
    		dp[i][p[j].first]%=mod;
    	}
    }
    for (int i=0;i<6;i++) {
    	res+=dp[n][i];
    	res%=mod;
    }
    cout<<res;
}