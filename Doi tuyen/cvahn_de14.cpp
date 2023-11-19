#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5],c[N+5];
pair<int,int>p[N+5];
vector<int>cprs,v;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
        p[i].first=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin();
        p[i].second=a[i];
        c[p[i].first]++;
    }
    for (int i=1;i<=n;i++) {
        if (c[p[i].first]==1) v.push_back(p[i].second);
    }
    cout<<v.size()<<'\n';
    for (auto i:v) cout<<i<<'\n';
}
