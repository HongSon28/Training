#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,f0,d,res1,res2;
pair<ll,ll>zero,cur;
vector<pair<ll,ll>>v,f1,f2;
ll calc(pair<ll,ll>a,pair<ll,ll>b) {
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool comp(pair<ll,ll>a,pair<ll,ll>b) {
    return calc(a,zero)<calc(b,zero);
}
bool comp2(pair<ll,ll>a,pair<ll,ll>b) {
    return calc(a,cur)<calc(b,cur);
}
int main() {
    cin>>n>>f0>>d;
    d*=d;
    for (int i=1;i<=n;i++) {
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    zero=v[f0-1];
    v.erase(v.begin()+f0-1);
    sort(v.begin(),v.end(),comp);
    for (int i=0;i<v.size();i++) {
        if (calc(v[i],zero)<=d) {
            res1++;
            f1.push_back(v[i]);
        } else f2.push_back(v[i]);
    }
    for (int i=0;i<f2.size();i++) {
        cur=f2[i];
        sort(f1.begin(),f1.end(),comp2);
        if (calc(f1[0],f2[i])<=d) res2++;
    }
    cout<<res1<<' '<<res2;
}
