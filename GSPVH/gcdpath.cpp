#include<bits/stdc++.h>
using namespace std;
const int N=3e5,M=1500000;
int sub,n;
int a[N+5];
pair<int,int>edge[N+5];
vector<int>id[M+5];
long long cntdiv[M+5],cnt[M+5],res;
int par[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
long long join(int x,int y) {
	x=find_root(x);
	y=find_root(y);
	if (x==y) return 0;
	long long res=1ll*par[x]*par[y];
	if (par[x]>par[y]) swap(x,y);
	par[x]+=par[y];
	par[y]=x;
	return res;
}
int main() {
	freopen("gcdpath.inp","r",stdin);
	freopen("gcdpath.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>sub>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
    	cin>>edge[i].first>>edge[i].second;
    	id[__gcd(a[edge[i].first],a[edge[i].second])].push_back(i);
    }
    for (int i=1;i<=M;i++) {
    	for (int j=i;j<=M;j+=i) 
    		for (auto e:id[j]) cntdiv[i]+=join(edge[e].first,edge[e].second);
    	for (int j=i;j<=M;j+=i)
    		for (auto e:id[j]) par[edge[e].first]=par[edge[e].second]=-1;
    }
    for (int i=M;i>=1;i--) {
    	cnt[i]=cntdiv[i];
    	for (int j=i*2;j<=M;j+=i) cnt[i]-=cnt[j];
    	res+=cnt[i]*i;
    }
    cout<<res;
}