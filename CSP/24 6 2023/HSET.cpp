#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long MOD=1e9+7;
long long power(long long x, long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%MOD;
    if (n%2==0) {
        long long res=temp*temp;
        res%=MOD;
        return res;
    } else {
        long long res=((x%MOD)*temp)%MOD*temp;
        res%=MOD;
        return res;
    }
}
int n,q;
long long a[N+5],b[N+5];
long long hash_a[N+5],hash_b[N+5];
long long base=7;
void create_hash_a() {
    for (int i=1;i<=n;i++) hash_a[i]=(hash_a[i-1]+power(base,a[i]))%MOD;
}
void create_hash_b() {
    for (int i=1;i<=n;i++) hash_b[i]=(hash_b[i-1]+power(base,b[i]))%MOD;
}
int main() {
    freopen("HSET.INP","r",stdin);
    freopen("HSET.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    create_hash_a();
    create_hash_b();
    cin>>q;
    while (q--) {
        int l,r,u,v;
        cin>>l>>r>>u>>v;
        long long suma=((hash_a[r]-hash_a[l-1])%MOD+MOD)%MOD;
        long long sumb=((hash_b[v]-hash_b[u-1])%MOD+MOD)%MOD;
        if(suma==sumb) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
