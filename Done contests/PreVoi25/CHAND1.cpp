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
        if (n>10||q>10) return false;
        for (int i=1;i<=n;i++) {
            if (c[i]>2||adj[i].size()>2) return false;
        }
        return true;
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
int main() {
    freopen("CHAND.INP","r",stdin);
    freopen("CHAND.ANS","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //if (sub1::check()) sub1::solve();
    //sub23::solve();
    sub5::solve();
}
/*
5 3
1 2 3 4 5
1 2
2 3 3 4
4 5
1 3
3 5
1 5
*/
