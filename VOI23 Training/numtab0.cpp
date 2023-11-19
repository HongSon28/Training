#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+5][N+5];
int vis[N+5],assigned[N+5],cnt,t;
vector<vector<int>>adj(N+5);
vector<pair<int,int>>res;
int pos[N+5],b[N+5];
bool visit(int u) {
    if (vis[u]!=t) vis[u]=t;
    else return false;
    for (auto v:adj[u]) {
        if (!assigned[v]||visit(assigned[v])) {
            assigned[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==1) {
                adj[j].push_back(i);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        t++;
        cnt+=visit(i);
    }
    if (cnt!=n) {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        pos[i]=i;
        b[i]=i;
    }
    for (int i=1;i<=n;i++) {
        if (pos[i]==assigned[i]) continue;
        res.push_back({pos[i],assigned[i]});
        int temp=b[assigned[i]],t2=temp;
        b[assigned[i]]=i;
        b[pos[i]]=temp;
        temp=pos[i];
        pos[i]=assigned[i];
        pos[t2]=temp;
        temp=b[assigned[i]];
    }
    cout<<res.size()<<'\n';
    for (auto p:res) cout<<1<<' '<<p.first<<' '<<p.second<<'\n';
}
