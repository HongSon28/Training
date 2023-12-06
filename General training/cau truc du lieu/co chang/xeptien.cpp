#include<bits/stdc++.h>
using namespace std;
bool comp(pair <int,int>a, pair<int,int>b) {
    if (a.second==b.second)
        return a.first>b.first;
    return a.second<b.second;
}
int main() {
    int n;
    cin>>n;
    pair<int,int>p[n];
    for (int i=0;i<n;i++) {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,comp);
    for (int i=0;i<n;i++)
        cout<<p[i].first<<' '<<p[i].second<<endl;
}
