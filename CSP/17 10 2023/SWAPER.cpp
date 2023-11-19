#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int cur;
int p[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SWAPER.INP","r",stdin);
    freopen("SWAPER.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=2*n;i++) p[i]=i;
    cur=n;
    while (m--) {
        int u,v;
        cin>>u>>v;
        if (u>n&&v>n) swap(p[u],p[v]);
        else if (u<=n&&v<=n) swap(p[u],p[v]);
        else if (u<=n&&v>n) {
            if (p[v]<=n) cur++;
            if (p[u]<=n) cur--;
            swap(p[u],p[v]);
        } else {
            if (p[u]<=n) cur++;
            if (p[v]<=n) cur--;
            swap(p[u],p[v]);
        }
        cout<<cur<<'\n';
    }
}
