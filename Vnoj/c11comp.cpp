#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SQ=320;
int n,m,k,q;
vector<vector<int>>adj(N+5);
int v[N+5];
int timer;
int st[N+5],en[N+5],tour[N+5];
pair<int,int>u[N+5];
int cnt[N+5],cur=1,res[N+5];
int lo=1,hi=1;
void dfs(int u) {
    timer++;
    st[u]=timer;
    tour[timer]=v[u];
    for (auto v:adj[u]) dfs(v);
    en[u]=timer;
}
bool comp(pair<int,int>x,pair<int,int>y) {
    int a=x.first,b=y.first;
    if (st[a]/SQ!=st[b]/SQ) return st[a]<st[b];
    return en[a]<en[b];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=2;i<=n;i++) {
        int j;
        cin>>j;
        adj[j].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>v[i];
    dfs(1);
//    for (int i=1;i<=n;i++) cout<<st[i]<<' '<<en[i]<<endl;
    cin>>q;
    for (int i=1;i<=q;i++) {
        cin>>u[i].first;
        u[i].second=i;
    }
    sort(u+1,u+1+q,comp);
    cnt[tour[1]]++;
    //for (int i=1;i<=timer;i++) cout<<tour[i]<<' ';
    //cout<<endl;
    for (int i=1;i<=q;i++) {
        int l=st[u[i].first],r=en[u[i].first];
        //cout<<u[i].first<<' '<<l<<' '<<r<<' '<<lo<<' '<<hi<<'\n';
        while (hi>r) {
            int x=tour[hi];
            cnt[x]--;
            cur-=cnt[x]==0;
            cur+=cnt[x]==k;
            hi--;
            //cout<<lo<<' '<<hi<<' '<<cur<<endl;
        }
        while (hi<r) {
            hi++;
            int x=tour[hi];
            cur+=cnt[x]==0;
            cur-=cnt[x]==k;
            cnt[x]++;
            //cout<<lo<<' '<<hi<<' '<<cur<<endl;
        }
        while (lo<l) {
            int x=tour[lo];
            cnt[x]--;
            cur-=cnt[x]==0;
            cur+=cnt[x]==k;
            lo++;
            //cout<<lo<<' '<<hi<<' '<<cur<<endl;
        }
        while (lo>l) {
            lo--;
            int x=tour[lo];
            cur+=cnt[x]==0;
            cur-=cnt[x]==k;
            cnt[x]++;
            //cout<<lo<<' '<<hi<<' '<<cur<<endl;
        }
        res[u[i].second]=cur;
    }
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}
