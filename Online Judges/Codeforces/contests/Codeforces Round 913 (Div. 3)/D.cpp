#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
pair<int,int>p[N+5];
int l,r;
bool check(int k) {
	l=0;
	r=0;
	for (int i=1;i<=n;i++) {
		l-=k;
		r+=k;
		if (l>p[i].second||r<p[i].first) return false;
		l=max(l,p[i].first);
		r=min(r,p[i].second);
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    	int lo=0,hi=1e9,res=1e9;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (check(mid)) {
    			res=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	cout<<res<<'\n';
    }
}