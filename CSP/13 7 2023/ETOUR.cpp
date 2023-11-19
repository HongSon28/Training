#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int t;
int deg[N+5];
int main() {
    freopen("ETOUR.INP","r",stdin);
    freopen("ETOUR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while (t--) {
        memset(deg,0,sizeof(deg));
        cin>>n>>m;
        int odd=0;
        for (int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        for (int i=1;i<=n;i++)
            if (deg[i]%2==1) odd++;
        if (odd==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
