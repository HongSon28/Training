#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[1003],s[1003];
int main(){
    freopen("CHIAMANG.INP","r",stdin);
    freopen("CHIAMANG.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    if(s[n]%2==1){
        cout<<0;
        return 0;
    }
    ll x=s[n]/2;
    for(int i=1;i<=n;i++)
        if(s[i]==x) m=i;
    cout<<m;
}
