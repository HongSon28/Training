#include<bits/stdc++.h>
using namespace std;
bool comp (pair<int,int>a,pair<int,int>b) {
    double ta=(double)a.first/(double)a.second;
    double tb=(double)b.first/(double)b.second;
    return ta<tb;
}
int main() {
    freopen("FAREY.INP","r",stdin);
    freopen("FAREY.OUT","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (__gcd(i,j)==1)
                v.push_back({j,i});
        }
    }
    sort(v.begin(),v.end(),comp);
    for (int i=0;i<v.size();i++) cout<<v[i].first<<' '<<v[i].second<<endl;
}
