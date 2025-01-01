#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
int a[N+5],b[N+5];
namespace sub1{
    int cnt[N+5];
    void solve() {
        while (q--) {
            int x,y,u,v,res=0;
            cin>>x>>y>>u>>v;
            for (int i=x;i<=y;i++) cnt[a[i]]++;
            for (int i=u;i<=v;i++) res+=cnt[b[i]],cout<<b[i]<<' '<<cnt[b[i]]<<'\n';
            for (int i=x;i<=y;i++) cnt[a[i]]--;
            cout<<res<<'\n';
        }
    }
}
namespace subfull{
    int id[N+5],pos[N+5];
    int res[N+5];
    struct Query{
        int u,v,type,id;
    };
    vector<Query>vc[N+5];
    struct Fenwick{
        int bit[N+5];
        void update(int idx) {
            while (idx<=n) {
                bit[idx]++;
                idx+=(idx&(-idx));
            }
        }
        int Get(int idx) {
            int ans=0;
            while (idx>0) {
                ans+=bit[idx];
                idx-=(idx&(-idx));
            }
            return ans;
        }
        int get(int l,int r) {
            return Get(r)-Get(l-1);
        }
    }bit;
    void solve() {
        for (int i=1;i<=n;i++) {
            id[a[i]]=i;
            a[i]=i;
        }
        for (int i=1;i<=n;i++) {
            b[i]=id[b[i]];
            pos[b[i]]=i;
        }
        for (int i=1;i<=q;i++) {
            int x,y,u,v;
            cin>>x>>y>>u>>v;
            vc[x-1].push_back({u,v,-1,i});
            vc[y].push_back({u,v,1,i});
        }
        for (int i=1;i<=n;i++) {
            bit.update(pos[i]);
            for (auto qu:vc[i]) {
                res[qu.id]+=qu.type*bit.get(qu.u,qu.v);
            }
        }
        for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
    }
}
int main() {
    freopen("PER.INP","r",stdin);
    freopen("PER.ANS","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    subfull::solve();
}

