#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n;
long long a[N+5],mx,mn,res=LLONG_MIN;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		a[i]+=a[i-1];
	}
	for (int i=1;i<=n;i++) {
		if (i<n) res=max(res,a[i]-mn);
		if (i>1) res=max(res,a[n]-a[i-1]+mx);
		mx=max(mx,a[i-1]);
		mn=min(mn,a[i]);
	}
	cout<<res;
}