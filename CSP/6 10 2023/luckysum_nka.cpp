#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2]={4,7},b[10],sum;
vector<ll>v;
void cre(ll n, ll k){
    for(int i=0;i<2;i++){
        b[k]=a[i];
        if(k==n){
            ll x=0;
            for(int i=1;i<n;i++){
                x+=b[i];
                x*=10;
            }
            x+=b[n];
            v.push_back(x);
        }
        else cre(n,k+1);
    }
}
int main(){
    freopen("luckysum.inp","r",stdin);
    freopen("luckysum_nka.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a,b; cin>>a>>b;
    for(int i=1;i<=9;i++) cre(i,1);
    v.push_back(4444444444);
    if(b<=v[0]){
        cout<<(b-a+1)*v[0];
        return 0;
    }
    ll l=0,r=v.size()-1,ra=0,lb=0,rb=0;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]>=a){
            ra=m;
            r=m-1;
        } else l=m+1;
    }
    l=0,r=v.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]<=b){
            lb=m;
            l=m+1;
        } else r=m-1;
    }
    l=0,r=v.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]>=b){
            rb=m;
            r=m-1;
        } else l=m+1;
    }
    sum+=(v[ra]-a+1)*v[ra]+(b-v[lb])*v[rb];
    for(int i=ra;i<lb;i++) sum+=(v[i+1]-v[i])*v[i+1];
    cout<<sum;
}

