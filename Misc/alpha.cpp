
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll mod=1e9+7;
ll giaithua[N+3];
ll power(ll a, ll n){
    if(n==0) return 1;
    ll temp=power(a,n/2);
    temp=temp*temp%mod;
    if(n%2==0) return temp;
    return temp*a%mod;
}
int main(){
    giaithua[0]=1;
    for(int i=1;i<=N;i++){
        giaithua[i]=giaithua[i-1]*i;
        giaithua[i]%=mod;
    }
    int t; cin>>t;
    while(t--){
        int m,n; cin>>m>>n;
        ll sum=0;
        for(int i=0;i<=m;i++) {
            sum+=giaithua[n]*power((giaithua[i]*giaithua[n-i]),mod-2);
            cout<<giaithua[n]*power((giaithua[i]*giaithua[n-i]),mod-2)<<endl;
        }
        cout<<sum<<'\n';
    }
}
