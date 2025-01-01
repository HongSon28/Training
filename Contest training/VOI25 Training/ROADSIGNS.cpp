#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n;
int x[N+5],a[N+5],b[N+5];
pair<int,int>p[N+5];
vector<int>cprs;
map<int,int>id;
vector<pair<int,int>>pos[N+5];
int cnt[N+5];
int get(int l,int r) {
	r--;
	return cnt[r]-cnt[l-1];
}
int res[N+5],c[N+5],inf=1e9;
void solve() {
	cprs.clear();
	for (int i=1;i<=n;i++) pos[i].clear();
	id.clear();
	for (int i=1;i<=n;i++) cprs.push_back(p[i].first);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=0;i<(int)cprs.size();i++) id[cprs[i]]=i+1;
	for (int i=1;i<=n;i++) {
		int cid=id[p[i].first];
		if (pos[cid].empty()||pos[cid].back().second+1!=i) pos[cid].push_back({i,i});
		else pos[cid][pos[cid].size()-1].second++;
	}
	for (int i=1;i<n;i++) {
		cnt[i]=cnt[i-1]+(p[i].second!=p[i+1].second);
	}
	int m=cprs.size();
	for (int i=1;i<=m;i++) {
		int l=0,r=0;
		while (l<(int)pos[i].size()) {
			r=l;
			int cur=-inf;
			while (r+1<(int)pos[i].size()) {
				if (get(pos[i][r].second+1,pos[i][r+1].first-1)!=0) break;
				int col=p[pos[i][r].second+1].second;
				if (cur==-inf) {
					cur=col;
					r++;
				} else if (cur==col) r++;
				else break;
			}
			int ans=pos[i][r].second,t=ans;
			int lo=ans+1,hi;
			if (r+1<pos[i].size()) hi=pos[i][r+1].first-1;
			else hi=n;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (cur==-inf) {
					if (get(t+1,mid)==0) {
						ans=mid;
						lo=mid+1;
					} else hi=mid-1;
				} else {
					if (get(t+1,mid)==0&&p[t+1].second==cur) {
						ans=mid;
						lo=mid+1;
					} else hi=mid-1;
				}
			}
			for (int j=l;j<=r;j++) {
				for (int k=pos[i][j].first;k<=pos[i][j].second;k++) {
					if (res[k]<ans) {
						res[k]=ans;
						c[k]=1;
					} else if (res[k]==ans) c[k]++;
					//if (k==578) cout<<l<<' '<<r<<' '<<cur<<' '<<pos[i].size()<<' '<<pos[i][j].first<<' '<<pos[i][j].second<<' '<<ans<<endl;
				}
			}
			for (int j=pos[i][r].second+1;j<=ans;j++) {
				if (res[j]<ans) {
					res[j]=ans;
					c[j]=1;
				} else if (res[j]==ans) c[j]++;
			}
			/*
			cout<<i<<' '<<cprs[i-1]<<endl;
			cout<<l<<' '<<r<<' '<<ans<<endl;
			for (auto [u,v]:pos[i]) cout<<u<<' '<<v<<endl;
			cout<<endl;*/
			if (l==r) l=r+1;
			else l=r;
		}
	}
}
int main() {
	freopen("ROADSIGNS.INP","r",stdin);
	freopen("ROADSIGNS.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>x[i]>>a[i]>>b[i];
		p[i]={x[i]-a[i],x[i]+b[i]};
	}
	solve();
	for (int i=1;i<=n;i++) swap(p[i].first,p[i].second);
	solve();
	int mx=0,cnt=0;
	for (int i=1;i<=n;i++) {
		int cur=res[i]-i+1;
		if (cur>mx) {
			mx=cur;
			cnt=c[i];
		} else if (mx==cur) cnt+=c[i];
	}
	cout<<mx<<' '<<cnt;
}
