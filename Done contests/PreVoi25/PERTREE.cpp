#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
vector<int>adj[N+5];
int p[N+5],a[N+5],mod=1e9+7;
bool used[N+5];
int res[N+5];
int cur[N+5];
void add(int &x,int y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void rec(int i) {
    if (i==n+1) {
        for (int j=1;j<=n;j++) add(res[j],a[cur[j]]);
        return;
    }
    for (int j=cur[p[i]]+1;j<=n;j++) {
        if (used[j]) continue;
        cur[i]=j;
        used[j]=true;
        rec(i+1);
        used[j]=false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    rec(1);
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}
