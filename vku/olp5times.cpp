#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n,q;
long long a[N+5],st[N*4+5],mod=1e9+7,res[N*2+5];
struct qu{
	int l,r,x,k,id;
	bool operator < (const qu &other) const {
		return x<other.x;
	}
};
vector<qu>query;
void build() {
	for (int i=1;i<=N*4;i++) st[i]=1;
}
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]*=a[pos];
		st[id]%=mod;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	st[id]=(st[id*2]*st[id*2+1])%mod;
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 1;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	long long g1=get(id*2,l,mid,u,v),g2=get(id*2+1,mid+1,r,u,v);
	return (g1*g2)%mod;
}
pair<long long,int>p[N+5];
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long divi(long long x,long long y) {
	return (x*power(y,mod-2))%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    build();
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	p[i]={a[i],i};
    }
    sort(p+1,p+1+n);
    int pos=1;
    for (int i=1;i<=q;i++) {
    	int l,r,x,y,k;
    	cin>>l>>r>>x>>y>>k;
    	query.push_back({l,r,x-1,k,i});
    	query.push_back({l,r,y,k,i+q});
    }
    sort(query.begin(),query.end());
    for (auto [l,r,x,k,id]:query) {
    	while (pos<=n&&p[pos].first<=x) {
    		update(1,1,n,p[pos].second);
    		pos++;
    	}
    	res[id]=power(get(1,1,n,l,r),k);
    }
    for (int i=1;i<=q;i++) cout<<divi(res[i+q],res[i])<<'\n';
}