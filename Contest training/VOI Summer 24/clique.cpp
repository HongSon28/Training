#include<bits/stdc++.h>
using namespace std;
const int N=600;
int t,n,m,k;
vector<int>adj[N+5];
struct dat{
	int i;
	long long c,d;
};
bool flag;
map<pair<long long,long long>,dat>mp;
map<pair<long long,long long>,int>last;
int clique(long long c,long long d) {
	if (__builtin_popcount(c)+__builtin_popcount(d)<k) return -1;
	if (last.find(make_pair(c,d))!=last.end()) return last[make_pair(c,d)];
	if (flag) return -2;
	int cur=0;
	for (int i=1;i<=n;i++) {
		if (d>>i&1) {
			long long mask=0;
			for (auto v:adj[i]) mask|=(1<<v);
			int temp=clique(c|(1<<i),d&mask)+1;
			if (temp==-1) continue;
			if (temp==-2) break;
			if (cur<temp){
				cur=temp;
				mp[make_pair(c,d)]={i,c|(1<<i),d&mask};
				if (cur==k) break;
				//cout<<c<<' '<<d<<' '<<(c|(1<<i))<<' '<<(d&mask)<<endl;
			}
		}
	}
	if (cur==k&&!flag) {
		flag=true;
		for (int i=1;i<=k;i++) {
			dat temp=mp[make_pair(c,d)];
			cout<<temp.i<<' ';
			c=temp.c,d=temp.d;
		}
		cout<<'\n';
	}
	return last[make_pair(c,d)]=cur;
}
void solve1() {
	mp.clear();
	last.clear();
	int mask=0;
	for (int i=1;i<=n;i++) {
		mask|=(1<<i);
		adj[i].clear();
	}
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	flag=false;
	clique(0,mask);
	if (!flag) cout<<-1<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m>>k;
    	solve1();
    }
}
