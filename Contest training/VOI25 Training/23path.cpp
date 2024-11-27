#include<bits/stdc++.h>
using namespace std;
const int N=1e5,B=317;
int n,q,m;
struct edge{
	int u,v,a,b;
	bool operator < (const edge &other) const {
		return a<other.a;
	}
}ed[N+5];
bool cmped(edge x,edge y) {
	return x.b<y.b;
}
struct query{
	int u,v,a,b,id;
	bool operator < (const query &other) const {
		return b<other.b;
	}
}qu[N+5];
struct DSU {
	int p[N/2+5],mx2[N/2+5],mx3[N/2+5],top;
	struct op{
		int u,pu,mx2u,mx3u,v,pv,mx2v,mx3v;
	} ops[N+5];
	void init() {
		memset(p,-1,sizeof(p));
		memset(mx2,-1,sizeof(mx2));
		memset(mx3,-1,sizeof(mx3));
		top=0;
	}
	int find_root(int u) {
		if (p[u]<0) return u;
		return find_root(p[u]);
	}
	void Union(int u,int v,int a,int b) {
		u=find_root(u),v=find_root(v);
		if (p[u]>p[v]) swap(u,v);
		ops[++top]={u,p[u],mx2[u],mx3[u],v,p[v],mx2[v],mx3[v]};
		mx2[u]=max(mx2[u],a);
		mx3[u]=max(mx3[u],b);
		if (u!=v) {
			p[u]+=p[v];
			mx2[u]=max(mx2[u],mx2[v]);
			mx3[u]=max(mx3[u],mx3[v]);
			p[v]=u;
		}
	}
	void roll_back() {
		auto [u,pu,mx2u,mx3u,v,pv,mx2v,mx3v]=ops[top];
		top--;
		p[u]=pu; mx2[u]=mx2u; mx3[u]=mx3u;
		p[v]=pv; mx2[v]=mx2v; mx3[v]=mx3v;
	}
} dsu;
bool res[N+5];
query cur[N+5];
int main() {	
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    dsu.init();
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>ed[i].u>>ed[i].v>>ed[i].a>>ed[i].b;
    sort(ed+1,ed+1+m);
    cin>>q;
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].u>>qu[i].v>>qu[i].a>>qu[i].b;
    	qu[i].id=i;
    }
    sort(qu+1,qu+1+q);
    for (int i=1;i<=m;i+=B) {
    	int cnt=0;
    	for (int j=1;j<=q;j++) {
    		if (qu[j].a>=ed[i].a&&(i+B>m||qu[j].a<ed[i+B].a)) cur[++cnt]=qu[j];
    	}
    	if (!cnt) continue;
    	dsu.init();
    	sort(ed+1,ed+i,cmped);
    	int k=1;
    	for (int j=1;j<=cnt;j++) {
    		while (k<i&&ed[k].b<=cur[j].b) {
    			dsu.Union(ed[k].u,ed[k].v,ed[k].a,ed[k].b);
    			k++;
    		}
    		int added=0;
    		for (int t=i;t<=min(m,i+B-1);t++) {
    			if (ed[t].a<=cur[j].a&&ed[t].b<=cur[j].b) {
    				added++;
    				dsu.Union(ed[t].u,ed[t].v,ed[t].a,ed[t].b);
    			}
    		}
    		int x=dsu.find_root(cur[j].u),y=dsu.find_root(cur[j].v);
    		res[cur[j].id]=(x==y&&dsu.mx2[x]==cur[j].a&&dsu.mx3[x]==cur[j].b);
    		while (added--) dsu.roll_back();
    	}
    }
    for (int i=1;i<=q;i++) {
    	if (res[i]) cout<<"Yes"<<'\n';
    	else cout<<"No"<<'\n';
    }
}