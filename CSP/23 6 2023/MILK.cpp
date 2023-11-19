#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int k;
int f[N+5],s[N+5];
int res=-1;
bool check(int m) {
    vector<int>v;
    for (int i=1;i<=n;i++) v.push_back(f[i]);
    for (int i=1;i<=m;i++) v.push_back(s[i]);
    sort(v.begin(),v.end());
    int i=0;
    int day=0;
    while (i<v.size()) {
        for (int j=1;j<=k;j++) {
            if (i>=v.size()) return true;
            if (v[i]<day) return false;
            i++;
        }
        day++;
    }
    return true;
}
int main() {
    freopen("MILK.INP","r",stdin);
    freopen("MILK.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>f[i];
    for (int i=1;i<=m;i++) cin>>s[i];
    sort(f+1,f+1+n);
    sort(s+1,s+1+n,greater<int>());
    int lo=0,hi=m;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
