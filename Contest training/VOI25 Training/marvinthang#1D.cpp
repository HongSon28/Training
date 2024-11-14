#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
vector<int>adj[N+5];
int dp[N+5],mx[N+5],d[N+5],p[N+5],res=1e9,cnt;
void dfs(int u,int par) {
	int mx1=0,mx2=0;
	p[u]=par;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		d[u]=max(d[u],d[v]+1);
		mx[u]=max(mx[u],mx[v]);
		if (mx2<d[v]+1) mx2=d[v]+1;
		if (mx1<mx2) swap(mx1,mx2);
	}
	mx[u]=max(mx[u],mx1+mx2);
}
void update(pair<int,int>&m1,pair<int,int>&m2,pair<int,int>&m3,int val,int p) {
	if (m3.first<val) m3={val,p};
	pair<int,int>temp[3];
	temp[0]=m1,temp[1]=m2,temp[2]=m3;
	sort(temp,temp+3);
	m1=temp[2],m2=temp[1],m3=temp[0];
}
void dfs2(int u,int par,int up) {
	pair<int,int>m1,m2,m3,tx1,tx2;
	for (auto v:adj[u]) {
		if (v!=par) {
			update(m1,m2,m3,d[v]+1,v);
			if (tx2.first<mx[v]) tx2={mx[v],v};
			if (tx1<tx2) swap(tx1,tx2);
		}
	}
	if (u!=1) update(m1,m2,m3,up,par);
	for (auto v:adj[u]) {
		if (v==par) continue;
		int val;
		if (m1.second==v) val=m2.first+m3.first;
		else if (m2.second==v) val=m1.first+m3.first;
		else val=m1.first+m2.first;
		/*
		if (v==2) {
			cout<<"RES "<<dp[u]<<' '<<val<<endl;
			cout<<m1.first<<' '<<m1.second<<endl;
			cout<<m2.first<<' '<<m2.second<<endl;
			cout<<m3.first<<' '<<m3.second<<endl;
		}
		*/
		dp[v]=max(dp[u],val);
		if (tx1.second==v) dp[v]=max(dp[v],tx2.first);
		else dp[v]=max(dp[v],tx1.first);
		int temp;
		if (m1.second==v) temp=m2.first;
		else temp=m1.first;
		dfs2(v,u,max(up+1,temp+1));
	}
}
int trace[N+5];
void dfs3(int u,int par,int ban) {
	for (auto v:adj[u]) {
		if (v==par||v==ban) continue;
		d[v]=d[u]+1;
		trace[v]=u;
		dfs3(v,u,ban);
	}
}
int findcen(int root,int ban) {
	memset(d,0,sizeof(d));
	dfs3(root,0,ban);
	int pos=0,mx=0;
	for (int i=1;i<=n;i++) {
		if (mx<d[i]) {
			pos=i;
			mx=d[i];
		}
	}
	/*
	int p=pos;
	cout<<mx<<endl;
	for (int i=1;i<=mx;i++) {
		cout<<p<<' ';
		p=trace[p];
	}
	cout<<p<<endl;
	*/
	memset(d,0,sizeof(d));
	memset(trace,0,sizeof(trace));
	dfs3(pos,0,ban);
	mx=0;
	for (int i=1;i<=n;i++) {
		if (mx<d[i]) {
			mx=d[i];
			pos=i;
		}
	}
	/*
	vector<int>vc;
	cout<<mx<<endl;
	for (int i=1;i<=mx;i++) {
		vc.push_back(pos);
		pos=trace[pos];
	}
	vc.push_back(pos);
	reverse(vc.begin(),vc.end());
	for (auto x:vc) cout<<x<<' ';
	cout<<endl;
	*/
	for (int i=1;i<=n;i++) {
		if (d[i]==(mx+1)/2) return i;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0,0);
	//for (int i=1;i<=n;i++) cout<<dp[i]<<'\n';
	int pos;
	for (int i=2;i<=n;i++) {
		int cur=max({dp[i],mx[i],(dp[i]+1)/2+(mx[i]+1)/2+1});
		//cout<<i<<' '<<mx[i]<<' '<<dp[i]<<' '<<cur<<endl;
		if (res>cur) {
			res=cur;
			pos=i;
		}
	}
	cout<<res<<'\n'<<p[pos]<<' '<<pos<<'\n';
	cout<<findcen(1,pos)<<' '<<findcen(pos,p[pos]);
}
