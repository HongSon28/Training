#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t;
int n,q;
int a[N+5],sum[N+5];
map<int,int>mp;
vector<int>pos[N+5];
bool check(int l,int r) {
	int t=-1,s=-1;
	int pt=mp[sum[r]],lo=0,hi=pos[pt].size()-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (pos[pt][mid]>=l) {
			hi=mid-1;
			s=pos[pt][mid];
		} else lo=mid+1;
	}
	if (s==-1) return false;
	pt=mp[sum[l-1]],lo=0,hi=pos[pt].size()-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (pos[pt][mid]>s) {
			hi=mid-1;
			t=pos[pt][mid];
		} else lo=mid+1;
	}
	return (t!=-1&&t<r);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>q;
    	int cur=0;
    	mp.clear();
    	for (int i=1;i<=n;i++) {
    		pos[i].clear();
    		cin>>a[i];
    		sum[i]=(sum[i-1]^a[i]);
    		if (mp[sum[i]]==0) mp[sum[i]]=++cur;
    		pos[mp[sum[i]]].push_back(i);
    	}
    	while (q--) {
    		int l,r;
    		cin>>l>>r;
    		//cout<<sum[l-1]<<' '<<sum[r]<<endl;
    		if (sum[l-1]==sum[r]||check(l,r)) cout<<"YES"<<'\n';
    		else cout<<"NO"<<'\n';
    	}
    	cout<<'\n';
    }
}