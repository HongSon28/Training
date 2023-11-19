#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const ll base=7;
const ll mod=1e9+7;
int a[N],b[N];
int n;
ll has1[N],has2[N];
void Read() {
    cin >> n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
}
ll power(ll x, ll y){
    if(y==0) return 1;
    ll temp=power(x,y/2);
    temp=(temp*temp)%mod;
    if(y%2==0) return temp%mod;
    return (temp*x)%mod;
}
ll get1(int l, int r)
{
    return ((has1[r] - has1[l - 1]) % mod + mod) % mod;
}
ll get2(int l, int r)
{
    return ((has2[r] - has2[l - 1]) % mod + mod) % mod;
}
ll f[N],q;
void Solve() {
    has1[0]=has2[0]=0;
    for(int i = 1; i <= n; i++) {
        has1[i] = (has1[i - 1] + power(base,a[i])) % mod;
    }
    for(int i = 1; i <= n; i++) {
        has2[i] = (has2[i - 1] + power(base,b[i])) % mod;
    }
    cin>>q;
    while(q--){
        int l,r,u,v;
        cin>>l>>r>>u>>v;
       // cout<<get1(l,r)<<' '<<get2(u,v)<<'\n';
        if(get1(l,r)==get2(u,v)) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
}
int main(){
    freopen("HSET.INP", "r", stdin);
    freopen("HSET.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Read();
    Solve();
}
/*
10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 8 0
5
1 3 2 4
5 7 6 8
8 8 10 10
3 9 9 9
1 2 8 9
*/

