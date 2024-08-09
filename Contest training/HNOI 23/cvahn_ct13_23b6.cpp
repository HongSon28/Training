#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,res;
pair<long long,long long>p[N+5];
vector<long long>v;
set<long long>s;
long long t;
int main() {
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    res=n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        if (p[i].second==1) v.push_back(p[i].first);
        else s.insert(p[i].first);
    }
    sort(v.begin(),v.end(),greater<long long>());
    cin>>t;
    for (auto x:v) {
        long long y=*(s.lower_bound(x));
        if (s.count(y)==0) continue;
        long long dif=y-x;
        if (dif<=2*t) {
            s.erase(y);
            res-=2;
        }
    }
    cout<<res;
}
