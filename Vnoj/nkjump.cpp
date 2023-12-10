#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int a[N+5],dp[N+5],res;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[i]=1;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
    	if (v.size()<2||a[i]!=v.back()||a[i]!=v[v.size()-2]) v.push_back(a[i]);
    }	
    for (int i=0;i<(int)v.size();i++) {
    	int t=i+1;
    	for (int j=0;j<i;j++) {
    		while (v[t]<=v[i]+v[j]&&t<(int)v.size()) {
    			if (v[t]==v[i]+v[j]) dp[t]=max(dp[t],max(dp[i],dp[j])+1);
    			t++;
    		}
    	}
    	res=max(res,dp[i]);
    }
    cout<<res;
}