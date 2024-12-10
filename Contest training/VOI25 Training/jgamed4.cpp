#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,x,y;
struct point{
	long long x,y;
	int id;
	bool operator < (const point &other) const {
		if (x!=other.x) return x<other.x;
		return y<other.y;
	}
} p[N+5];
bool comp(point a,point b) {
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
pair<long long,long long>pos[N+5];
vector<pair<int,long long>>adj[N+5];
long long calc(pair<long long,long long>x,pair<long long,long long>y) {
	return min(abs(x.first-y.first),abs(x.second-y.second));
}
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
long long d[N+5],inf=1e18+5,res=inf;
long long dist(pair<long long,long long>x,pair<long long,long long>y) {
	return abs(x.first-y.first)+abs(x.second-y.second);
}
priority_queue<dat>pq;
void dijk() {
	for (int i=1;i<=k;i++) d[i]=inf;
	pq.push({0,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (d[u]!=du) continue;
		for (auto [v,w]:adj[u]) {
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>x>>y;
    p[0]={x,y,0};
    pos[0]={x,y};
    for (int i=1;i<=k;i++) {
    	cin>>p[i].x>>p[i].y;
    	pos[i]={p[i].x,p[i].y};
    	p[i].id=i;
    }
    sort(p,p+1+k);
    for (int i=1;i<=k;i++) {
    	long long w=calc(pos[p[i].id],pos[p[i-1].id]);
    	adj[p[i].id].push_back(make_pair(p[i-1].id,w));
    	adj[p[i-1].id].push_back(make_pair(p[i].id,w));
    }
    sort(p,p+1+k,comp);
    for (int i=1;i<=k;i++) {
    	long long w=calc(pos[p[i].id],pos[p[i-1].id]);
    	adj[p[i].id].push_back(make_pair(p[i-1].id,w));
    	adj[p[i-1].id].push_back(make_pair(p[i].id,w));
    }
    dijk();
    for (int i=0;i<=k;i++) {
    	res=min(res,d[i]+dist(pos[i],make_pair(1,1)));
    	res=min(res,d[i]+dist(pos[i],make_pair(1,n)));
    	res=min(res,d[i]+dist(pos[i],make_pair(n,1)));
    	res=min(res,d[i]+dist(pos[i],make_pair(n,n)));
    }
    cout<<res;
}