#include<bits/stdc++.h>
using namespace std;
bool comp (pair<int,int>a,pair<int,int>b) {
    return b.first-a.first>b.second-a.second;
}
int main() {
    int n,sum=0;
    cin>>n;
    n*=2;
    pair<int,int>p[n+1];
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,comp);
    for (int i=1;i<=n/2;i++) sum+=p[i].first;
    for (int i=n/2+1;i<=n;i++) sum+=p[i].second;
    cout<<sum;
}
