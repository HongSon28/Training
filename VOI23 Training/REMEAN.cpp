#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
double a[N+5],b[N+5],sum,res,mn,mx;
bool check(double x) {
	double ans = -1e9;
    double cur = 0;
    for (int i=2;i<n;i++) {
        cur+=a[i]-x;
        ans=max(ans,cur);
        cur=max(cur,(double)0);    
    }
 
    return ans>=sum-n*x;
}
int main() {
	freopen("remean.inp","r",stdin);
	freopen("remean.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	double lo=0,hi=1e5;
	while (hi-lo>=1e-5) {
		double mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid;
		} else lo=mid;
	}
	cout.precision(3);
	cout<<fixed<<res;
}