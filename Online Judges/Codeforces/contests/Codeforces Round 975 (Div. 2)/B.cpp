#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,q;
struct seg{
	int l,r;
	long long val;
};
vector<seg>v;
int x[N+5];
map<long long,long long>mp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		mp.clear();
		v.clear();
		cin>>n>>q;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++) {
			long long l=i,r=n-i+1;
			v.push_back({x[i],x[i],l*r-1});
		}
		for (int i=2;i<=n;i++) {
			if (x[i-1]+1==x[i]) continue;
			long long l=i-1,r=n-i+1;
			v.push_back({x[i-1]+1,x[i]-1,l*r});
		}
		for (auto [l,r,val]:v) {
			//cout<<l<<' '<<r<<' '<<val<<endl;
			mp[val]+=r-l+1;
		}
		while (q--) {
			long long k;
			cin>>k;
			cout<<mp[k]<<' ';
		}
		cout<<endl;
	}
}