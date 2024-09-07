#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
struct dat{
	long long l,r,p;
	bool operator < (const dat &other) const {
		return l<other.l;
	}
} a[N+5];
long long res=-1,inf=1e18;
long long f[N+5];
bool check(long long v) {
	for (int i=1;i<=n;i++) {
		f[i]=inf;
		if (a[i].l==1&&a[i].p<=v) {
			f[i]=0;
			if (a[i].r==m) return true;
			//cout<<i<<' '<<0<<endl;
			continue;
		}
		for (int j=1;j<i;j++) {
			if (a[j].r>=a[i].l-1&&a[i].p+a[j].p<=v&&f[j]<=a[i].l-1)
				f[i]=min(f[i],a[j].r);
		}
		//cout<<i<<' '<<f[i]<<endl;
		if (f[i]!=inf&&a[i].r==m) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i].l>>a[i].r>>a[i].p;
	sort(a+1,a+1+n);
	long long lo=1,hi=2e9;
	while (lo<=hi) {
		long long mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<res;
}