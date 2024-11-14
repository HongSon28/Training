#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n;
pair<long long,long long>p[N+5];
long long pre_mx[N+5],pre_mn[N+5],suf_mx[N+5],suf_mn[N+5];
long long inf=1e18,res=inf;
namespace case1{
	void solve() {
		int l=0;
		for (int r=n;r>1;r--) {
			while (l>r-2) l--;
			while (l<r-2&&pre_mx[l+1]<=suf_mx[r]&&pre_mn[l+1]>=suf_mn[r]) l++;
			res=min(res,suf_mx[r]-suf_mn[r]+p[r-1].first-p[l+1].first); 
		}
	}
}
namespace case2{
	struct query{
		int p1,p2,id;
		bool operator < (const query &other) const {
			return p1<other.p1;
		}
	} q[N+5];
	long long ans[N+5],mx[N+5];
	int par[N+5];
	pair<long long,int>st[N+5];
	int top;
	int find_root(int u) {
		if (par[u]<0) return u;
		return par[u]=find_root(par[u]);
	}
	void Union(int u,int v) {
		if ((u=find_root(u))==(v=find_root(v))) return;
		if (par[u]>par[v]) swap(u,v);
		par[u]+=par[v];
		par[v]=u;
		mx[u]=max(mx[u],mx[v]);
	}
	void solve_query() {
		sort(q+1,q+n);
		int pos=1;
		while (pos<n&&q[pos].p1==-1) {
			ans[q[pos].id]=-1;
			pos++;
		}
		for (int i=0;i<n;i++) {
			mx[i]=pre_mn[i]+p[i+1].first;
			//cout<<i<<' '<<pre_mn[i]<<' '<<p[i+1].first<<' '<<mx[i]<<endl;
			while (top&&st[top].first<=pre_mn[i]+p[i+1].first) {
				Union(st[top].second,i);
				top--;
			}
			top++;
			st[top]={pre_mn[i]+p[i+1].first,i};
			while (pos<n&&q[pos].p1==i) {
				if (q[pos].p2==-1||q[pos].p1<q[pos].p2) ans[q[pos].id]=-1;
				else ans[q[pos].id]=mx[find_root(q[pos].p2)];
				//cout<<pos<<' '<<q[pos].p1<<' '<<q[pos].p2<<' '<<q[pos].id<<' '<<ans[q[pos].id]<<endl;
				pos++;
			}
		}
	}
	void solve() {
		top=0;
		for (int i=0;i<=n;i++) par[i]=-1;
		int p1=-1,p2=n;
		for (int r=n;r>1;r--) {
			q[r-1].id=r;
			while (p1>r-2) p1--;
			while (p1<r-2&&pre_mx[p1+1]<=suf_mx[r]) p1++;
			q[r-1].p1=p1;
			if (r==n) {
				p2=r-2;
				while (p2>=1&&pre_mn[p2-1]<suf_mn[r]) p2--;
				if (pre_mn[p2]>=suf_mn[r]) p2=r-1;
			} else {
				while (p2<=r-2&&pre_mn[p2]>=suf_mn[r]) p2++;
			}
			if (p2>r-2) q[r-1].p2=-1;
			else q[r-1].p2=p2;
		}
		solve_query();
		for (int r=n;r>1;r--) {
			//cout<<r<<' '<<ans[r]<<endl;
			if (ans[r]==-1) continue;
			res=min(res,suf_mx[r]+p[r-1].first-ans[r]);
		}
	}
}
namespace case3{
	struct query{
		int p1,p2,id;
		bool operator < (const query &other) const {
			return p1<other.p1;
		}
	} q[N+5];
	long long ans[N+5],mx[N+5];
	int par[N+5];
	pair<long long,int>st[N+5];
	int top;
	int find_root(int u) {
		if (par[u]<0) return u;
		return par[u]=find_root(par[u]);
	}
	void Union(int u,int v) {
		if ((u=find_root(u))==(v=find_root(v))) return;
		if (par[u]>par[v]) swap(u,v);
		par[u]+=par[v];
		par[v]=u;
		mx[u]=max(mx[u],mx[v]);
	}
	void solve_query() {
		sort(q+1,q+n);
		int pos=1;
		while (pos<n&&q[pos].p1==-1) {
			ans[q[pos].id]=-1;
			pos++;
		}
		for (int i=0;i<n;i++) {
			mx[i]=p[i+1].first-pre_mx[i];
			//cout<<i<<' '<<pre_mn[i]<<' '<<p[i+1].first<<' '<<mx[i]<<endl;
			while (top&&st[top].first<=p[i+1].first-pre_mx[i]) {
				Union(st[top].second,i);
				top--;
			}
			top++;
			st[top]={p[i+1].first-pre_mx[i],i};
			while (pos<n&&q[pos].p1==i) {
				if (q[pos].p2==-1||q[pos].p1<q[pos].p2) ans[q[pos].id]=-1;
				else ans[q[pos].id]=mx[find_root(q[pos].p2)];
				//cout<<pos<<' '<<q[pos].p1<<' '<<q[pos].p2<<' '<<q[pos].id<<' '<<ans[q[pos].id]<<endl;
				pos++;
			}
		}
	}
	void solve() {
		top=0;
		for (int i=0;i<=n;i++) par[i]=-1;
		int p1=-1,p2=n;
		for (int r=n;r>1;r--) {
			q[r-1].id=r;
			while (p1>r-2) p1--;
			while (p1<r-2&&pre_mn[p1+1]>=suf_mn[r]) p1++;
			q[r-1].p1=p1;
			if (r==n) {
				p2=r-2;
				while (p2>=1&&pre_mx[p2-1]>suf_mx[r]) p2--;
				if (pre_mx[p2]<=suf_mx[r]) p2=r-1;
			} else {
				while (p2<=r-2&&pre_mx[p2]<=suf_mx[r]) p2++;
			}
			if (p2>r-2) q[r-1].p2=-1;
			else q[r-1].p2=p2;
		}
		solve_query();
		for (int r=n;r>1;r--) {
			//cout<<r<<' '<<ans[r]<<endl;
			if (ans[r]==-1) continue;
			res=min(res,-suf_mn[r]+p[r-1].first-ans[r]);
		}
	}
}
namespace case4{
	struct query{
		int p1,p2,id;
		bool operator < (const query &other) const {
			return p1<other.p1;
		}
	} q[N+5];
	long long ans[N+5],mx[N+5];
	int par[N+5];
	pair<long long,int>st[N+5];
	int top;
	int find_root(int u) {
		if (par[u]<0) return u;
		return par[u]=find_root(par[u]);
	}
	void Union(int u,int v) {
		if ((u=find_root(u))==(v=find_root(v))) return;
		if (par[u]>par[v]) swap(u,v);
		par[u]+=par[v];
		par[v]=u;
		mx[u]=max(mx[u],mx[v]);
	}
	void solve_query() {
		sort(q+1,q+n);
		int pos=1;
		while (pos<n&&q[pos].p1==-1) {
			ans[q[pos].id]=-1;
			pos++;
		}
		for (int i=0;i<n;i++) {
			mx[i]=p[i+1].first-pre_mx[i]+pre_mn[i];
			//cout<<i<<' '<<pre_mn[i]<<' '<<p[i+1].first<<' '<<mx[i]<<endl;
			while (top&&st[top].first<=p[i+1].first-pre_mx[i]+pre_mn[i]) {
				Union(st[top].second,i);
				top--;
			}
			top++;
			st[top]={p[i+1].first-pre_mx[i]+pre_mn[i],i};
			while (pos<n&&q[pos].p1==i) {
				if (q[pos].p2==-1||q[pos].p1<q[pos].p2) ans[q[pos].id]=-1;
				else ans[q[pos].id]=mx[find_root(q[pos].p2)];
				//cout<<pos<<' '<<q[pos].p1<<' '<<q[pos].p2<<' '<<q[pos].id<<' '<<ans[q[pos].id]<<endl;
				pos++;
			}
		}
	}
	void solve() {
		top=0;
		for (int i=0;i<=n;i++) par[i]=-1;
		int pos;
		for (int r=n;r>1;r--) {
			q[r-1].id=r;
			if (r==n) {
				pos=r-2;
				while (pos>=1&&pre_mx[pos-1]>suf_mx[r]&&pre_mn[pos-1]<suf_mn[r]) pos--;
				if (pre_mx[pos]<=suf_mx[r]||pre_mn[pos]>=suf_mn[r]) pos=r-1;
			} else {
				while (pos<=r-2&&((pre_mx[pos]<=suf_mx[r])||(pre_mn[pos]>=suf_mn[r]))) pos++;
			}
			if (pos>r-2) q[r-1].p2=-1;
			else q[r-1].p2=pos;
			q[r-1].p1=r-2;
			//cout<<r<<' '<<pos<<endl;
		}
		solve_query();
		for (int r=n;r>1;r--) {
			//cout<<r<<' '<<ans[r]<<endl;
			if (ans[r]==-1) continue;
			res=min(res,p[r-1].first-ans[r]);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    pre_mn[0]=suf_mn[n+1]=inf;
    for (int i=1;i<=n;i++) {
        pre_mx[i]=max(pre_mx[i-1],p[i].second);
        pre_mn[i]=min(pre_mn[i-1],p[i].second);
    }
    for (int i=n;i>=1;i--) {
        suf_mx[i]=max(suf_mx[i+1],p[i].second);
        suf_mn[i]=min(suf_mn[i+1],p[i].second);
    }
    case1::solve();
    case2::solve();
    case3::solve();
    case4::solve();
    for (int r=n;r>1;r--) {
        long long s1=p[n].first-p[r].first;
        long long s2=pre_mx[r-1]-pre_mn[r-1];
        res=min(res,s1+s2);
    }
    cout<<res;
}
