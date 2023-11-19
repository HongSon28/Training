#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
#define ll long long
pair<ll,ll>p[N+5];
ll prep,res,type,u,v,k;
bool comp(pair<ll,ll>x,pair<ll,ll>y) {
    if (x.second-x.first==y.second-y.first) return x.first<y.first;
    return x.second-x.first>y.second-y.first;
}
int main() {
    //freopen("SCHEDU.INP","r",stdin);
    //freopen("SCHEDU.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=n;i++) {
        prep+=p[i].first;
        res=max(res,prep)+p[i].second;
    }
    while (m--) {
        cin>>type;
        if (type==1) cin>>u>>v;
        else cin>>k;
    }
    cout<<res;
}
