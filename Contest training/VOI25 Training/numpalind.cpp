#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
string s,t;
struct query{
	int l,r,mid,type,id;
	bool operator < (const query &other) const {
		if (mid!=other.mid) return mid<other.mid;
		return type>other.type;
	}
} qu[N+5]; 
long long res[N+5];
long long base=311,mod=1e9+7;
long long power[N+5],hsa[N+5],hsb[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hsa[i]=(hsa[i-1]*base+s[i])%mod;
		hsb[i]=(hsb[i-1]*base+t[i])%mod;
	}
}
long long geta(int l,int r) {
	return (hsa[r]-hsa[l-1]*power[r-l+1]+mod*mod)%mod;
}
long long getb(int l,int r) {
	return (hsb[r]-hsb[l-1]*power[r-l+1]+mod*mod)%mod;
}
vector<pair<int,int>>p1,p2;
struct SegmentTree{
	long long st[N*4+5],lazy[N*4+5];
	void reset() {
		memset(st,0,sizeof(st));
		memset(lazy,0,sizeof(lazy));
	}
	void down(int id,int l,int r,int mid) {
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t;
		lazy[id*2+1]+=t;
		st[id*2]+=(mid-l+1)*t;
		st[id*2+1]+=(r-mid)*t;
	}
	void update(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id]+=r-l+1;
			lazy[id]++;
			return;
		}
		int mid=(l+r)/2;
		down(id,l,r,mid);
		update(id*2,l,mid,u,v);
		update(id*2+1,mid+1,r,u,v);
		st[id]=st[id*2]+st[id*2+1];
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		down(id,l,r,mid);
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} tree;
void solve_odd() {
	int cur=0;
	for (int i=1;i<=q;i++) {
		int t=qu[i].mid;
		while (cur<(int)p1.size()&&p1[cur].first<=t) {
			tree.update(1,1,n,p1[cur].first-p1[cur].second,p1[cur].first);
			cur++;
		}
		res[qu[i].id]+=tree.get(1,1,n,qu[i].l,t);
	}
	tree.reset();
	cur=p1.size()-1;
	for (int i=q;i>=1;i--) {
		int t=qu[i].mid+1;
		while (cur>=0&&p1[cur].first>=t) {
			tree.update(1,1,n,p1[cur].first,p1[cur].first+p1[cur].second);
			cur--;
		}
		res[qu[i].id]+=tree.get(1,1,n,t,qu[i].r);
	} 
}
bool comp(query a,query b) {
	if (a.mid!=b.mid) return a.mid<b.mid;
	return a.type<b.type;
}
void solve_even() {
	tree.reset();
	sort(qu+1,qu+1+q,comp);
	int cur=0;
	for (int i=1;i<=q;i++) {
		int t=qu[i].mid;
		if (qu[i].type==1) t--;
		while (cur<(int)p2.size()&&p2[cur].first<=t) {
			tree.update(1,1,n,p2[cur].first-p2[cur].second,p2[cur].first);
			cur++;
		}
		res[qu[i].id]+=tree.get(1,1,n,qu[i].l,t);
	}
	tree.reset();
	cur=p2.size()-1;
	for (int i=q;i>=1;i--) {
		int t=qu[i].mid;
		if (qu[i].type==2) t++;
		while (cur>=0&&p2[cur].first>=t) {
			tree.update(1,1,n,p2[cur].first+1,p2[cur].first+1+p2[cur].second);
			cur--;
		}
		res[qu[i].id]+=tree.get(1,1,n,t,qu[i].r);
	}
}
int main() {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    cin>>s;
    t=s; reverse(t.begin(),t.end());
    s=' '+s; t=' '+t;
    prep();
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].l>>qu[i].r;
    	qu[i].id=i;
    	qu[i].mid=(qu[i].l+qu[i].r)/2;
    	if ((qu[i].r-qu[i].l+1)%2==0) qu[i].type=2;
    	else qu[i].type=1;
    }
    sort(qu+1,qu+1+q);
    for (int i=1;i<=n;i++) {
    	int ans=0,lo=1,hi=n;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		int left=i-mid,right=i+mid;
    		if (left>=1&&right<=n&&geta(left,i)==getb(n-right+1,n-i+1)) {
    			ans=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	p1.push_back({i,ans});
    	//cout<<i-ans<<' '<<i+ans<<endl;
    }
    for (int i=1;i<n;i++) {
    	if (s[i]!=s[i+1]) continue;
    	int ans=0,lo=1,hi=n;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		int left=i-mid,right=i+1+mid;
    		if (left>=1&&right<=n&&geta(left,i)==getb(n-right+1,n-(i+1)+1)) {
    			ans=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	p2.push_back({i,ans});
    	//cout<<i-ans<<' '<<i+1+ans<<endl;
    }
    solve_odd();
    solve_even();
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}