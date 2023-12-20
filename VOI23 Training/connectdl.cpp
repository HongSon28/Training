#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,c1,c2,p,q,par1[N+5],par2[N+5];
long long mod,res;
struct edge{
	int type,u,v;
	long long w;
	bool operator < (const edge &other) const {
		return w<other.w;	
	}
};
vector<edge>vc;
int find1(int u) {
	if (par1[u]<0) return u;
	return par1[u]=find1(par1[u]); 
}
void union1(int u,int v) {
	u=find1(u);
	v=find1(v);
	if (par1[v]<par1[u]) swap(u,v);
	par1[u]+=par1[v];
	par1[v]=u;
}
int find2(int u) {
	if (par2[u]<0) return u;
	return par2[u]=find2(par2[u]); 
}
void union2(int u,int v) {
	u=find2(u);
	v=find2(v);
	if (par2[v]<par2[u]) swap(u,v);
	par2[u]+=par2[v];
	par2[v]=u;
}
long long mul(long long x,long long y){
	if (y==1) return x%mod;
	long long ans=mul(x,y/2);
	ans=(ans+ans)%mod;
	if (y%2==1) ans=(ans+x)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par1,-1,sizeof(par1));
    memset(par2,-1,sizeof(par2));
	cin>>n>>m>>p>>q>>mod;
	for (int i=1;i<=p;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		vc.push_back({1,u,v,w});
	} 
	for (int i=1;i<=q;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		vc.push_back({2,u,v,w});
	}
	sort(vc.begin(),vc.end());
	for (auto ed:vc) {
		int type=ed.type,u=ed.u,v=ed.v;
		long long w=ed.w;
		if (type==1) {
			int x=find1(u),y=find1(v);
			if (x==y) continue;
			union1(x,y);
			res+=mul(w%mod,(n-c2));
			res%=mod;
			c1++;
			//cout<<type<<' '<<u<<' '<<v<<' '<<w<<' '<<n-c2<<' '<<res<<endl;
		} else {
			int x=find2(u),y=find2(v);
			if (x==y) continue;
			union2(x,y);
			res+=mul(w%mod,(m-c1));
			res%=mod;
			c2++;
			//cout<<type<<' '<<u<<' '<<v<<' '<<w<<' '<<m-c1<<' '<<res<<endl;
		}
	}
	cout<<res;
}