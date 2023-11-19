#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7;
vector<ll>prime;
bool dmt[N+5];
bool p[N+5];
int c[N+5];
ll square(ll x) {
    ll lo=0,hi=1e8;
    ll res;
    while (lo<=hi) {
        ll mid=(lo+hi)/2;
        if (mid*mid<=x) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    return res;
}
void seive() {
    memset(p,true,sizeof(p));
    for (ll i=2;i<=N;i++) {
        if (p[i]) {
            for (ll j=i*2;j<=N;j+=i) p[j]=false;
            prime.push_back(i);
        }
    }
}
int main() {
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    seive();
    for (auto i:prime) {
        if (i!=3) dmt[i]=true;
    }
    for (int i=1;i<=N;i++) {
        if (dmt[i]) c[i]=c[i-1]+1;
        else c[i]=c[i-1];
    }
    int t;
    cin>>t;
    while (t--) {
        ll a,b,t1,t2;
        cin>>a>>b;
        a--;
        a/=9,b/=9;
        a=square(a);
        b=square(b);
        if (a<6561) t1=c[a];
        else t1=c[a]+1;
        if (b<6561) t2=c[b];
        else t2=c[b]+1;
        //cout<<a<<' '<<b<<' '<<c[a]<<' '<<c[b]<<endl;
        cout<<t2-t1<<endl;
    }
}
