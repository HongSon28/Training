#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[2005],s[2005];
vector<pair<ll,ll>>v;
int main(){
    freopen("TDOAN.INP","r",stdin);
    freopen("TDOAN.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[j]-s[i-1]==k) v.push_back(make_pair(j-i+1,i));
        }
    }
    if(v.size()==0) cout<<0;
    else{
        sort(v.begin(),v.end());
        cout<<v[0].second<<' '<<v[0].first;
    }
}
/* 21 17
 0 2 3 2 10 1 5 5 6 12 20 30 14 8 0 11 0 6 0 0 5 */

