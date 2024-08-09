#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
pair<int,int>p[N+5];
int t[N+5];
int a,b;
bool comp(pair<int,int>x,pair<int,int>y) {
    return min(x.first,y.second) < min(x.second,y.first);
}
int main() {
    freopen("LLGC2M.INP","r",stdin);
    freopen("LLGC2M.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=n;i++) {
        a+=p[i].first;
        b=max(b,a)+p[i].second;
    }
    cout<<b;
}
