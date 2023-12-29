#include<bits/stdc++.h>
using namespace std;
int n,m;
long long res,cnt,mx=LLONG_MIN,mn=LLONG_MAX;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		long long x;
    		cin>>x;
    		res+=abs(x);
    		if (x>=0) mn=min(mn,x);
    		else mx=max(mx,x),cnt++;
    	}
    }
    if (cnt%2==0) cout<<res;
    else {
    	if (mx+mn>=0) cout<<res+2*mx;
    	else cout<<res-2*mn;
    }
}