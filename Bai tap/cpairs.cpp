#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+7;
ll n,p,k,a[N];
map<ll,ll> mp;
int main()
{
    //freopen("cpairs.inp","r",stdin);
    //freopen("cpairs.out","w",stdout);
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]*((a[i]*a[i]*a[i]-k)%p+p)%p]++;
    }
    ll res=0;
    for(auto i=mp.begin();i!=mp.end();i++)
        res+=(i->second)*(i->second-1)/2;
    cout<<res;
}
