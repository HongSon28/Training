#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
	long double b,w,h,d;
	bool operator < (const dat &other) const {
		return b<other.b;
	}
} a[N+5];
long double res;
int n;
long double lo=0,hi=0;
long double v;
bool check(long double hg) {
	long double sum=0;
	for (int i=1;i<=n;i++) {
		if (a[i].b>hg) break;
		long double cur=min((long double)a[i].h,hg-a[i].b);
		sum+=cur*a[i].w*a[i].d;
	}
	return (sum<=v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>v;
    for (int i=1;i<=n;i++) {
    	cin>>a[i].b>>a[i].h>>a[i].w>>a[i].d;
    	hi=max(hi,a[i].b+a[i].h);
    }
    sort(a+1,a+1+n);
    while (hi-lo>=1e-5) {
    	long double mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		lo=mid;
    	} else hi=mid;
    }
    cout.precision(2);
    cout<<fixed<<res;
}