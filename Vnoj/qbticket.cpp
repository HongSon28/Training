#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long l[4],c[4],p[4];
int n,s,f;;
long long a[N+5],dp[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>l[1]>>l[2]>>l[3]>>c[1]>>c[2]>>c[3];
    cin>>n>>s>>f;
    for (int i=2;i<=n;i++) cin>>a[i];
    p[1]=p[2]=p[3]=s;
    for (int i=s+1;i<=f;i++) {
    	dp[i]=LLONG_MAX;
    	for (int j=1;j<=3;j++) {
    		while (p[j]<i&&a[p[j]]+l[j]<a[i]) p[j]++;
    		if (p[j]<i) dp[i]=min(dp[i],dp[p[j]]+c[j]);
    	}
    }
    cout<<dp[f];
}