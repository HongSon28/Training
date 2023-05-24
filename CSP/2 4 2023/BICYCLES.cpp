#include<bits/stdc++.h>
using namespace std;
int main () {
    int n,m,cnt=0,i=0;
    cin>>n>>m;
    vector<int>v;
    for (int t,i=0;i<n;i++) {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int l=0,r=1;
    for (int i=1;i<n;i++) {
        if (v[0]+v[i]>m) break;
        r=i;
    }
    while (l<r) {
        if (v[l]+v[r]<=m) {
            l++;
            r--;
            cnt++;
        } else r--;
    }
    cout<<n-cnt*2+cnt;
}
