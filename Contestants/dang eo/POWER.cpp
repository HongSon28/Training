#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000000;
vector<int>v;
void sang() {
    bool p[N+1];
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2; i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i)
                p[j]=false;
        }
    }
}
ll pow(ll i, ll j){
    ll t=1;
    for(ll p=1;p<=j;p++) t*=i;
    return t;
}
int main(){
    freopen("POWER.INP", "r", stdin);
    freopen("POWER.OUT", "w", stdout);
    sang();
    ll n,k;
    cin>>n>>k;
    ll a[n+3];
    for(int i=1;i<=n;i++) cin>>a[i];
    ll t,gcd,lcm=a[1];
    for(int i=1;i<=n;i++){
        gcd=__gcd(a[i],lcm);
        t=a[i]*lcm;
        lcm=t/gcd;
    }
    ll c=1;
    for(int i=0;i<v.size();i++){
       ll dem=0;
       while(lcm%v[i]==0){
            dem++;
            lcm/=v[i];
       }
       if(dem%k!=0) dem=dem/k*k+k;
       ll j=dem/k;
       c*=pow(v[i],j);
    }
    cout<<c;
}
