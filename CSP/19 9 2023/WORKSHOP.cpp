#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,res;
pair<long long,long long>p[N*2+5];
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
    if (a.first-a.second==b.first-b.second) return a.first<b.first;
    return a.first-a.second<b.first-b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("WORKSHOP.INP","r",stdin);
    freopen("WORKSHOP.OUT","w",stdout);
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=n/2;i++) res+=p[i].first;
    for (int i=n/2+1;i<=n;i++) res+=p[i].second;
    cout<<res;
}
