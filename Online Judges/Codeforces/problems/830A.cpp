#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,k,p;
long long a[N+5],res=1e18;
long long b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+k);
	for (int st=1;st+n-1<=k;st++) {
		long long cur=0;
		for (int i=st;i<=st+n-1;i++) cur=max(cur,abs(a[i-st+1]-b[i])+abs(b[i]-p));
		res=min(res,cur);
	}
	cout<<res;
}