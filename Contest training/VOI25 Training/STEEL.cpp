#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
pair<long long,long long>a[N+5],b[N+5];
vector<pair<long long,long long>>va,vb;
long long res;
void solve(int l,int r,int optl,int optr) {
	if (l>r) return;
	int mid=(l+r)/2;
	int opt=-1;
	long long mx=0;
	for (int i=optl;i<=optr;i++) {
		if (vb[i].first<=va[mid].first||vb[i].second<=va[mid].second) continue;
		long long temp=(vb[i].first-va[mid].first)*(vb[i].second-va[mid].second);
		if (temp>mx) {
			mx=temp;
			opt=i;
		}
	}
	res=max(res,mx);
	if (opt!=-1) {
		solve(l,mid-1,optl,opt);
		solve(mid+1,r,opt,optr);
	} else {
		int R=optr,L=optl;
		while (R>=optl&&vb[R].second<=va[mid].second) R--;
		if (R>=optl) solve(l,mid-1,optl,R);
		while (L<=optr&&vb[L].first<=va[mid].first) L++;
		if (L<=optr) solve(mid+1,r,L,optr);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i].first>>a[i].second;
    for (int i=1;i<=n;i++) cin>>b[i].first>>b[i].second;
    sort(a+1,a+1+m);
    sort(b+1,b+1+n);
    for (int i=1;i<=m;i++) {
    	if (va.empty()) {
    		va.push_back(a[i]);
    		continue;
    	} 
    	if (va.back().first==a[i].first) {
	    	if (va.back().second>a[i].second) {
	    		va.pop_back();
	    		va.push_back(a[i]);
	    	}
    	} else {
    		if (va.back().second>a[i].second) va.push_back(a[i]);
    	}
    }
    for (int i=n;i>=1;i--) {
    	if (vb.empty()) {
    		vb.push_back(b[i]);
    		continue;
    	}
    	if (vb.back().first==b[i].first) {
    		if (vb.back().second<b[i].second) {
    			vb.pop_back();
    			vb.push_back(b[i]);
    		}
    	} else {
    		if (vb.back().second<b[i].second) vb.push_back(b[i]);
    	}
    }
    reverse(vb.begin(),vb.end());
    solve(0,va.size()-1,0,vb.size()-1);
    cout<<res;
}