#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
int c[2*N+5];
int main() {
    freopen("FIND.INP","r",stdin);
    freopen("FIND.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    while (m--) {
        int u,v,k;
        cin>>u>>v>>k;
        memset(c,0,sizeof(c));
        for (int i=u;i<=v;i++) c[a[i]+N]++;
        for (int i=-N;i<=N;i++) {
            if (c[i+N]>=k) {
                cout<<i<<'\n';
                break;
            } else k-=c[i+N];
        }
    }
}
/*10 10
1 7 14 0 9 4 18 18 2 4
6 6 1
2 8 2
3 6 4
2 7 1
3 4 1
2 3 1
6 9 4
2 7 1
3 10 4
6 10 5
*/
