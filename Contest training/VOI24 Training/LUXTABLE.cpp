#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5],c0[N+5],c1[N+5];
map<pair<int,int>,int>mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("LUXTABLE.INP","r",stdin);
	freopen("LUXTABLE.OUT","w",stdout);
	cin>>t;
	while(t--) {
		int res=INT_MAX;
		mp.clear();
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			if (i%2==1) c1[a[i]]++;
			else c0[a[i]]++;
		}
		for (int i=1;i<n;i++) mp[{a[i],a[i+1]}]++;
		for (int i=1;i<n;i++) {
			int cur=n;
			cur+=mp[{a[i],a[i+1]}]-1;
			if (i%2==1) cur-=c1[a[i]]+c0[a[i+1]];
			else cur-=c0[a[i]]+c1[a[i+1]];
			res=min(res,cur);
		}
		for (int i=1;i<n;i++) c1[a[i]]=c0[a[i]]=0;
		cout<<res<<'\n';
	}
}
