#include <bits/stdc++.h>
#define ll long long
#define a first
#define b second
using namespace std;
const int N=1e5;
ll n,q;
ll s[N+4];
pair<ll,ll> p[N+4];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.b-x.a==y.b-y.a) return x.a<y.a;
    return x.b-x.a>y.b-y.a;
}
vector<ll>v;
int main(){
    //freopen("xayhangrao.inp","r",stdin);
    //freopen("xayhangrao.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>p[i].a;
    for(int i=1;i<=n;i++) cin>>p[i].b;
    sort(p+1,p+1+n,cmp);
    ll x=p[1].b;
    v.push_back(1e18);
    for(int i=2;i<=n;i++) v.push_back(p[i].a);
    sort(v.begin(),v.end(),greater<ll>());
    for(int i=1;i<=n;i++) s[i]=s[i-1]+v[i];
    while(q--){
        ll k; cin>>k;
        cout<<s[k-1]+x<<' ';
    }
}
