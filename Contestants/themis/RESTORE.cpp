#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long s,sum;
long long d[N+5];
bool used[(int)1e3],edge[(int)1e3][(int)1e3];
struct ed{
    int u,v;
    long long w;
};
vector<ed>res;
void dfs(int u,int par) {
    for (int v=1;v<=n;v++) {
        if (edge[u][v]&&par!=v) {
            res.push_back({u,v,d[v]-d[u]});
            sum+=d[v]-d[u];
            dfs(v,u);
        }
    }
}
void check() {
    sum=0;
    res.clear();
    dfs(1,0);
    if (sum==s) {
        for (int i=0;i<(int)res.size();i++) cout<<res[i].u<<' '<<res[i].v<<' '<<res[i].w<<'\n';
        exit(0);
    }
}
void rec(int cnt) {
    if (cnt==n) {
        check();
        return;
    }
    for (int i=1;i<=n;i++) {
        if (!used[i]) continue;
        for (int j=1;j<=n;j++) {
            if (used[j]) continue;
            used[j]=true;
            edge[i][j]=edge[j][i]=true;
            rec(cnt+1);
            used[j]=false;
            edge[i][j]=edge[j][i]=false;
        }
    }
}
void solve1(){
    used[1]=true;
    rec(1);
}
void solve2(int last){
    if (last==n) {
        for (int i=1;i<n;i++)  cout<<i<<' '<<i+1<<' '<<d[i+1]-d[i]<<'\n';
        return;
    }
    for (int i=1;i<last-1;i++) cout<<i<<' '<<i+1<<' '<<d[i+1]-d[i]<<'\n';
    cout<<last-1<<' '<<last+1<<' '<<d[last+1]-d[last-1]<<'\n';
    for (int i=last+1;i<n;i++) cout<<i<<' '<<i+1<<' '<<d[i+1]-d[i]<<'\n';
    cout<<n<<' '<<last<<' '<<d[last]-d[n];
}
void solve() {
    int last=n+1;
    for (int i=2;i<=n;i++) {
        if (d[i]==s){
            last=i;
            break;
        }
    }
    if (last==n+1) solve1();
    else solve2(last);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("RESTORE.INP","r",stdin);
    freopen("RESTORE.OUT","w",stdout);
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>d[i];
    solve();
}
