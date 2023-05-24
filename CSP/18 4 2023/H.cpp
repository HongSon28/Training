#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll res,cur;
vector<pair<ll,ll>>v;
bool comp(pair<ll,ll>a,pair<ll,ll>b) {
    if (a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}
int main() {
    freopen("H.INP","r",stdin);
    freopen("H.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        ll w,h;
        cin>>w>>h;
        w/=2;
        v.push_back(make_pair(w,h));
    }
    sort(v.begin(),v.end(),comp);
    res=v[0].first*v[0].second;
    cur=v[0].first;
    for (int i=1;i<v.size();i++) {
        if (v[i].first>cur) {
            res+=v[i].second*(v[i].first-cur);
            cur=v[i].first;
        }
    }
    cout<<res*2;
}
