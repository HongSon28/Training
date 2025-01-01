#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long x[N+5],y[N+5],r[N+5];
namespace sub2{
    vector<int>adj[N+5],adj2[N+5];
    long long dist(int i,int j) {
        return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    }
    bool vis[N+5];
    int deg[N+5];
    int res;
    void dfs(int u) {
        vis[u]=true;
        for (auto v:adj[u]) {
            if (!vis[v]) dfs(v);
        }
    }
    void dfs2(int u) {
        vis[u]=true;
        for (auto v:adj2[u]) {
            if (!vis[v]) dfs2(v);
        }
    }
    void solve() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<i;j++) {
                if (dist(i,j)<=r[i]*r[i]) {
                    adj[i].push_back(j);
                    adj2[i].push_back(j);
                    adj2[j].push_back(i);
                    deg[j]++;
                }
                if (dist(i,j)<=r[j]*r[j]) {
                    adj[j].push_back(i);
                    adj2[i].push_back(j);
                    adj2[j].push_back(i);
                    deg[i]++;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            if (!vis[i]&&!deg[i]) {
                res++;
                dfs(i);
            }
        }
        for (int i=n;i>=1;i--) {
            if (!vis[i]) {
                res++;
                dfs2(i);
            }
        }
        cout<<res;
    }
}
namespace sub3{
    const int M=1e6+1;
    int dp[N+5];
    pair<int,int>p[N+5];
    int L[N+5],R[N+5];
    int inf=1e9;
    bool check() {
        for (int i=1;i<=n;i++) {
            if (y[i]!=0) return false;
        }
        return true;
    }
    struct SegmentTree{
        pair<int,int> lazy[M*2*4+5],st[M*2*4+5];
        void build(int id,int l,int r) {
            if (l==r) {
                st[id]={inf,l};
                lazy[id]={inf,l};
                return;
            }
            int mid=(l+r)/2;
            build(id*2,l,mid);
            build(id*2+1,mid+1,r);
            lazy[id]=st[id]=min(st[id*2],st[id*2+1]);
        }
        void down(int id) {
            pair<int,int> t=lazy[id];
            lazy[id*2]=min(lazy[id*2],t);
            st[id*2]=min(st[id*2],t);
            lazy[id*2+1]=min(lazy[id*2+1],t);
            st[id*2+1]=min(st[id*2+1],t);
        }
        void update(int id,int l,int r,int u,int v,pair<int,int> val) {
            if (l>v||r<u) return;
            if (u<=l&&r<=v) {
                lazy[id]=min(lazy[id],val);
                st[id]=min(st[id],val);
                return;
            }
            down(id);
            int mid=(l+r)/2;
            update(id*2,l,mid,u,v,val);
            update(id*2+1,mid+1,r,u,v,val);
            st[id]=min(st[id*2],st[id*2+1]);
        }
        pair<int,int> get(int id,int l,int r,int u,int v) {
            if (l>v||r<u) return {inf,0};
            if (u<=l&&r<=v) return st[id];
            down(id);
            int mid=(l+r)/2;
            return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
        }
    } tree1,tree2;
    void solve() {
        for (int i=1;i<=n;i++) {
            p[i].first=x[i]+M;
            p[i].second=r[i];
        }
        tree1.build(1,1,M*2),tree2.build(1,1,M*2);
        sort(p+1,p+1+n);
        for (int i=1;i<=n;i++) {
            L[i]=max(p[i].first-p[i].second,1);
            R[i]=min(p[i].first+p[i].second,M*2);
        }
        for (int i=1;i<=n;i++) {
            pair<int,int>temp=tree1.get(1,1,M*2,L[i],R[i]);
            if (temp.first!=inf) dp[i]=dp[temp.second-1]+1;
            else dp[i]=dp[i-1]+1;
            //cout<<i<<' '<<temp.second<<' '<<dp[i]<<endl;
            temp=tree2.get(1,1,M*2,p[i].first,M*2);
            //cout<<"GET "<<p[i].first<<' '<<temp.first<<endl;
            dp[i]=min(dp[i],temp.first);
            //cout<<i<<' '<<p[i].first<<' '<<l[i]<<' '<<r[i]<<' '<<temp.first<<' '<<temp.second<<' '<<dp[i]<<endl;
            tree1.update(1,1,M*2,p[i].first,p[i].first,{dp[i],i});
            tree2.update(1,1,M*2,R[i],R[i],{dp[i],i});
            //cout<<"UPD "<<l[i]<<' '<<r[i]<<' '<<dp[i]<<' '<<i<<endl;
        }
        cout<<dp[n];
    }
}
int main() {
    freopen("WIFI.INP","r",stdin);
    freopen("WIFI.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];
    if (n<=1000) sub2::solve();
    else sub3::solve();
}
