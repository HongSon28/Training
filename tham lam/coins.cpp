#include<bits/stdc++.h>
using namespace std;
bool comp (pair<int,int>a, pair<int,int>b) {
    if (a.second-a.first==b.second-b.first) {
        return a.first<b.first;
    }
    return a.second-a.first<b.second-b.first;
}
int main() {
    int n,m;
    cin>>n>>m;
    pair<int,int>p[n];
    for (int i=0;i<n;i++) cin>>p[i].first;
    for (int i=0;i<n;i++) cin>>p[i].second;
    sort(p,p+n,comp);
    for (int i=0;i<n;i++) {
        if (p[i].second-p[i].first<=m) {
            m+=p[i].first;
        } else {
            break;
        }
    }
    cout<<m;
}
