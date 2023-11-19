#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,d;
int a[N+5];
map<int,int>mp;
int res;
int main() {
    freopen("LAS1.INP","r",stdin);
    freopen("LAS1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>d;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]]=mp[a[i]-d]+1;
        res=max(res,mp[a[i]]);
    }
    cout<<res;
}
