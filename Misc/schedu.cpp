#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
pair<long long,long long>p[N+5];
long long cur,res;
bool comp(pair<long long,long long>x,pair<long long,long long>y) {
    if (x.second!=y.second) return x.second>y.second;
    return x.first>y.first;
}
vector<pair<long long,long long>>v1,v2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SCHEDU.INP","r",stdin);
    freopen("SCHEDU.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        if (p[i].first<=p[i].second) v1.push_back(p[i]);
        else v2.push_back(p[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),comp);
    for (auto i:v2) v1.push_back(i);
    for (auto t:v1) {
        cur+=t.first;
        res=max(res,cur)+t.second;
    }
    while (m--) {
        int type;
        cin>>type;
        int u,v,k;
        if (type==1) cin>>u>>v;
        else cin>>k;
    }
    cout<<res;
}
