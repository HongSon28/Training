#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
pair<int,int>p[N+5],b[N+5];
int a[N+5];
vector<int>cprs;
struct BIT{
	int bit[N+5];
	void update(int idx) {
		while (idx<=m) {
			bit[idx]++;
			idx+=(idx&(-idx));
		}
	}
	int get(int idx) {
		int res=0;
		while (idx>0) {
			res+=bit[idx];
			idx-=(idx&(-idx));
		}
		return res;
	}
} tree;
map<int,int>pos;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i].first>>p[i].second;
		b[i]=p[i];
		cprs.push_back(p[i].first);
		cprs.push_back(p[i].second);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (auto x:cprs) pos[x]=x;
	m=cprs.size();
	for (int i=1;i<=m;i++) a[i]=i;
	for (int i=1;i<=n;i++) {
		p[i].first=lower_bound(cprs.begin(),cprs.end(),p[i].first)-cprs.begin()+1;
		p[i].second=lower_bound(cprs.begin(),cprs.end(),p[i].second)-cprs.begin()+1;
		swap(a[p[i].first],a[p[i].second]);
		int t=pos[b[i].first];
		pos[b[i].first]=pos[b[i].second];
		pos[b[i].second]=t;
	}
	long long res=0;
	for (int i=m;i>=1;i--) {
		res+=tree.get(a[i]-1);
		tree.update(a[i]);
	}
	vector<pair<int,int>>vp;
	for (auto i=pos.begin();i!=pos.end();i++) vp.push_back({i->second,i->first});
	sort(vp.begin(),vp.end());
	vector<int>vc;
	for (auto [u,v]:vp) {
		vc.push_back(v);
		//cout<<u<<' '<<v<<endl;
	}
	for (auto x:vc) {
		int l=pos[x],r=x;
		if (l>r) swap(l,r);
		else if (l==r) continue;
		int cnt=r-l-1;
		int rl=-1,rr=-1;
		int lo=0,hi=vp.size()-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (vp[mid].first>l) {
				rl=mid;
				hi=mid-1;
			} else lo=mid+1;
		}
		lo=0,hi=vp.size()-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (vp[mid].first<r) {
				rr=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		if (rl!=-1&&rr!=-1&&rl<=rr) res+=cnt-(rr-rl+1);
		else res+=cnt;
	}
	cout<<res;
}