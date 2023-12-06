#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
    if ((a.second-a.first>=0&&b.second-b.first<0)||(a.second-a.first<0&&b.second-b.first>=0)) return a.second-a.first>b.second-b.first;
    if (a.second-a.first>=0&&b.second-b.first>=0) return a.first<b.first;
    if (a.second-a.first<0&&b.second-b.first<0&&a.second!=b.second) return a.second>b.second;
    if (a.second-a.first<0&&b.second-b.first<0&&a.second==b.second) return a.first<b.first;
}
int main() {
    long long n;
    cin>>n;
    pair<long long,long long>p[n];
    for (int i=0;i<n;i++) cin>>p[i].first;
    for (int i=0;i<n;i++) cin>>p[i].second;
    sort(p,p+n,comp);
    long long res=p[0].first;
    long long money=p[0].second;
    for (int i=1;i<n;i++) {
        if (money<p[i].first) {
            res+=p[i].first-money;
            money=p[i].first;
        }
        money+=p[i].second-p[i].first;
    }
    cout<<res;
}
