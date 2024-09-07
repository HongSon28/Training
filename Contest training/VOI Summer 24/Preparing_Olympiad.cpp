#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
long long l,r,x,c[N+5],res,inf=1e18;
void rec(int k,long long sum,long long mn,long long mx) {
	if (k==n+1) {
		res+=(sum>=l&&sum<=r&&mx-mn>=x);
		return;
	}
	rec(k+1,sum+c[k],min(mn,c[k]),max(mx,c[k]));
	rec(k+1,sum,mn,mx);
}
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>l>>r>>x;
    for (int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n);
    rec(1,0,inf,-inf);
    cout<<res;
}