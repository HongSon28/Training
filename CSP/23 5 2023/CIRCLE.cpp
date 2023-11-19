#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
struct circle{
    long long x,y,r;
};
circle a[N+5];
bool vis[N+5];
vector<vector<int>>adj(N+5);
vector<int>t;
bool check(int i,int j) {
    long long dif=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
    long long t1=(a[i].r+a[j].r)*(a[i].r+a[j].r);
    //cout<<dif<<' '<<t1<<endl;
    if (dif<=t1) return true;
    return false;
}
void dfs(int u) {
    for (auto v:adj[u]) {
        if (!vis[v]) {
            vis[v]=true;
            t.push_back(v);
            dfs(v);
        }
    }
}
int main() {
    freopen("CIRCLE.INP","r",stdin);
    freopen("CIRCLE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].r;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (check(i,j)) {
                //cout<<i<<' '<<j<<endl;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            t.clear();
            vis[i]=true;
            t.push_back(i);
            dfs(i);
            sort(t.begin(),t.end());
            for (auto j:t) cout<<j<<' ';
            cout<<endl;
        }
    }
}
