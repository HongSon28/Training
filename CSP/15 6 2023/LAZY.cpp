#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long c[N+5];
long long x[N+5];
long long res;
int n,k;
int main() {
    freopen("LAZY.INP","r",stdin);
    freopen("LAZY.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        long long a,b;
        cin>>a>>b;
        x[b]+=a;
    }
    for (int i=0;i<=N;i++)
        c[i]=c[i-1]+x[i];
    //for (int i=1;i<=15;i++) cout<<i<<' '<<c[i]<<endl;
    for (int i=1;i<=N;i++) {
        int l=max(0,i-k);
        int r=min(N,i+k);
        res=max(res,c[r]-c[l-1]);
    }
    cout<<res;
}
