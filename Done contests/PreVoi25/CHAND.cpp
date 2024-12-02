#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int c[N+5],pos[N+5],a[N+5];
vector<int>adj[N+5];
void dfs(int u,int par,int cur) {
    a[cur]=u;
    pos[u]=cur;
    for (auto v:adj[u]) {
        if (v!=par) dfs(v,u,cur+1);
    }
}
namespace sub1{
    const int M=10;
    pair<int,int>query[M+1];
    int col[M+1],inf=1e9;
    bool check() {
        int cnt=0;
        if (n>10||q>10) return false;
        for (int i=1;i<=n;i++) {
            if (c[i]>2||adj[i].size()>2) return false;
            if (adj[i].size()==1) cnt++;
        }
        return (cnt==2);
    }
    bool valid(int qu) {
        for (int i=1;i<=qu;i++) {
            int l=pos[query[i].first],r=pos[query[i].second];
            while (l<r) {
                if(col[l]!=col[r]) return false;
                l++;r--;
            }
        }
        return true;
    }
    void solve() {
        for (int i=1;i<=n;i++) {
            if (adj[i].size()==1) {
                dfs(i,0,1);
                break;
            }
        }
        for (int i=1;i<=q;i++) {
            cin>>query[i].first>>query[i].second;
            int ans=inf;
            for (int mask=0;mask<(1<<n);mask++) {
                int cur=0;
                for (int j=1;j<=n;j++) {
                    col[j]=((mask>>(j-1))&1)+1;
                    cur+=(col[j]!=c[j]);
                }
                if (valid(i)) {
                    ans=min(ans,cur);
                }
            }
            cout<<ans<<'\n';
        }
    }
}
namespace sub23{
    bool check() {
        if (n>200||q>200) return false;
        int cnt=0;
        for (int i=1;i<=n;i++) {
            if (adj[i].size()>2) return false;
            if (adj[i].size()==1) cnt++;
        }
        return (cnt==2);
    }
    const int M=200;
    int p[M+5];
    long long val[M+5];
    vector<long long>vc[M+5];
    int find_root(int u) {
        if (p[u]<0) return u;
        return p[u]=find_root(p[u]);
    }
    void Union(int u,int v) {
        if ((u=find_root(u))==(v=find_root(v))) return;
        if (p[u]>p[v]) swap(u,v);
        p[u]+=p[v];
        p[v]=u;
        for (auto x:vc[v]) vc[u].push_back(x);
        vc[v].clear();
        sort(vc[u].begin(),vc[u].end());
        int sz=vc[u].size();
        long long mid;
        if (sz%2==0) mid=(vc[u][sz/2-1]+vc[u][sz/2])/2;
        else mid=vc[u][sz/2];
        val[u]=0;
        for (auto x:vc[u]) val[u]+=abs(x-mid);
    }
    void solve() {
        memset(p,-1,sizeof(p));
        for (int i=1;i<=n;i++) {
            vc[i].push_back(c[i]);
        }
        for (int i=1;i<=n;i++) {
            if (adj[i].size()==1) {
                dfs(i,0,1);
                break;
            }
        }
        for (int qu=1;qu<=q;qu++) {
            int l,r;
            cin>>l>>r;
            l=pos[l],r=pos[r];
            while (l<r) {
                Union(l,r);
                l++;
                r--;
            }
            long long res=0;
            for (int i=1;i<=n;i++) {
                if (p[i]<0) res+=val[i];
            }
            cout<<res<<'\n';
        }
    }
}
namespace sub5{
    bool check() {
        int cnt=0;
        for (int i=1;i<=n;i++) {
            if (adj[i].size()>2) return false;
            if (adj[i].size()==1) cnt++;
        }
        return (cnt==2);
    }
    int p[N+5];
    long long val[N+5];
    multiset<long long>l[N+5],r[N+5];
    long long suml[N+5],sumr[N+5];
    int find_root(int u) {
        if (p[u]<0) return u;
        return p[u]=find_root(p[u]);
    }
    void update(long long x,int u) {
        int cursz=l[u].size()+r[u].size();
        long long mid;
        if (cursz%2==1) mid=(*l[u].rbegin());
        else mid=((*l[u].rbegin())+(*r[u].begin()))/2;
        //cout<<"UPD "<<x<<' '<<mid<<endl;
        if (x<=mid) {
            l[u].insert(x);
            suml[u]+=x;
        } else {
            r[u].insert(x);
            sumr[u]+=x;
        }
        int ls=l[u].size(),rs=r[u].size();
        while (ls-rs>=2) {
            long long cur=(*l[u].rbegin());
            suml[u]-=cur;
            sumr[u]+=cur;
            l[u].erase(l[u].lower_bound(*l[u].rbegin()));
            r[u].insert(cur);
            ls=l[u].size(),rs=r[u].size();
        }
        while (rs-ls>=1) {
            long long cur=(*r[u].begin());
            sumr[u]-=cur;
            suml[u]+=cur;
            r[u].erase(r[u].begin());
            l[u].insert(cur);
            ls=l[u].size(),rs=r[u].size();
        }
    }
    void Union(int u,int v) {
        if ((u=find_root(u))==(v=find_root(v))) return;
        if (p[u]>p[v]) swap(u,v);
        p[u]+=p[v];
        p[v]=u;
        for (auto x:l[v]) update(x,u);
        for (auto x:r[v]) update(x,u);
        l[v].clear();
        r[v].clear();
        /*
        cout<<endl;
        for (auto x:l[u]) cout<<x<<' ';
        cout<<endl;
        for (auto x:r[u]) cout<<x<<' ';
        cout<<endl<<u<<' '<<suml[u]<<' '<<sumr[u]<<endl;
        */
        int ls=l[u].size(),rs=r[u].size();
        int cursz=ls+rs;
        long long mid;
        if (cursz%2==1) mid=(*l[u].rbegin());
        else mid=(*l[u].rbegin()+(*r[u].begin()))/2;
        val[u]=(mid*ls-suml[u])+(sumr[u]-mid*rs);
    }
    void solve() {
        memset(p,-1,sizeof(p));
        for (int i=1;i<=n;i++) {
            l[i].insert(c[i]);
            suml[i]=c[i];
        }
        for (int i=1;i<=n;i++) {
            if (adj[i].size()==1) {
                dfs(i,0,1);
                break;
            }
        }
        for (int qu=1;qu<=q;qu++) {
            int l,r;
            cin>>l>>r;
            l=pos[l],r=pos[r];
            while (l<r) {
                Union(l,r);
                l++;
                r--;
            }
            long long res=0;
            for (int i=1;i<=n;i++) {
                if (p[i]<0) {
                    //cout<<i<<' '<<val[i]<<endl;
                    res+=val[i];
                }
            }
            cout<<res<<'\n';
        }
    }
}
namespace subfull{
    int p[N+5];
    long long val[N+5];
    multiset<long long>l[N+5],r[N+5];
    long long suml[N+5],sumr[N+5];
    int find_root(int u) {
        if (p[u]<0) return u;
        return p[u]=find_root(p[u]);
    }
    void update(long long x,int u) {
        int cursz=l[u].size()+r[u].size();
        long long mid;
        if (cursz%2==1) mid=(*l[u].rbegin());
        else mid=((*l[u].rbegin())+(*r[u].begin()))/2;
        if (x<=mid) {
            l[u].insert(x);
            suml[u]+=x;
        } else {
            r[u].insert(x);
            sumr[u]+=x;
        }
        int ls=l[u].size(),rs=r[u].size();
        while (ls-rs>=2) {
            long long cur=(*l[u].rbegin());
            suml[u]-=cur;
            sumr[u]+=cur;
            l[u].erase(l[u].lower_bound(*l[u].rbegin()));
            r[u].insert(cur);
            ls=l[u].size(),rs=r[u].size();
        }
        while (rs-ls>=1) {
            long long cur=(*r[u].begin());
            sumr[u]-=cur;
            suml[u]+=cur;
            r[u].erase(r[u].begin());
            l[u].insert(cur);
            ls=l[u].size(),rs=r[u].size();
        }
    }
    void Union(int u,int v) {
        if ((u=find_root(u))==(v=find_root(v))) return;
        if (p[u]>p[v]) swap(u,v);
        p[u]+=p[v];
        p[v]=u;
        for (auto x:l[v]) update(x,u);
        for (auto x:r[v]) update(x,u);
        l[v].clear();
        r[v].clear();
        int ls=l[u].size(),rs=r[u].size();
        int cursz=ls+rs;
        long long mid;
        if (cursz%2==1) mid=(*l[u].rbegin());
        else mid=(*l[u].rbegin()+(*r[u].begin()))/2;
        val[u]=(mid*ls-suml[u])+(sumr[u]-mid*rs);
    }
    const int LG=__lg(N);
    int up[N+5][LG+5],h[N+5];
    void dfs(int u) {
        for (auto v:adj[u]) {
            if (v==up[u][0]) continue;
            h[v]=h[u]+1;
            up[v][0]=u;
            for (int j=1;j<=LG;j++) {
                up[v][j]=up[up[v][j-1]][j-1];
            }
            dfs(v);
        }
    }
    int lca(int u,int v) {
        if (h[u]!=h[v]) {
            if (h[u]<h[v]) swap(u,v);
            int k=h[u]-h[v];
            for (int j=0;(1<<j)<=k;j++) {
                if ((k>>j)&1)
                    u=up[u][j];
            }
        }
        if (u==v) return u;
        int k=__lg(h[u]);
        for (int j=k;j>=0;j--) {
            if (up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];
    }
    void solve() {
        memset(p,-1,sizeof(p));
        for (int i=1;i<=n;i++) {
            l[i].insert(c[i]);
            suml[i]=c[i];
        }
        dfs(1);
        for (int qu=1;qu<=q;qu++) {
            int l,r;
            cin>>l>>r;
            int k=lca(l,r);
            vector<int>v1,v2;
            while (l!=k) {
                v1.push_back(l);
                l=up[l][0];
            }
            v1.push_back(k);
            while (r!=k) {
                v2.push_back(r);
                r=up[r][0];
            }
            reverse(v2.begin(),v2.end());
            for (auto x:v2) v1.push_back(x);
            int pl=0,pr=v1.size()-1;
            while (pl<pr) {
                Union(v1[pl],v1[pr]);
                pl++;
                pr--;
            }
            long long res=0;
            for (int i=1;i<=n;i++) {
                if (p[i]<0) {
                    res+=val[i];
                }
            }
            cout<<res<<'\n';
        }
    }
}
int main() {
    freopen("CHAND.INP","r",stdin);
    freopen("CHAND.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    subfull::solve();
}
/*
5 3
1 2 3 4 5
1 2
2 3
3 4
4 5
1 3
3 5
1 5
*/
