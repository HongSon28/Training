#include<bits/stdc++.h>
using namespace std;
const int N=500,S=1e5;
int n;
int c[N+5],dp[N+5][S+5],sum;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>c[i];
    	sum+=c[i];
    }
    for (int i=1;i<=sum;i++) dp[0][i]=S+5;
    for (int i=1;i<=n;i++) {
    	for (int s=sum-c[i];s>=0;s--) {
    		dp[i][s]=min({dp[i-1][s]+c[i],dp[i-1][s+c[i]],dp[i-1][abs(s-c[i])]});
    	}
    }
    int res=sum-dp[n][0];
    cout<<dp[n][0]+res/2;
}