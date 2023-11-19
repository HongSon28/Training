#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5],b[N+5];
map<int,int>mp;
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CPAIRS.INP","r",stdin);
    freopen("CPAIRS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        cin>>b[i];
        mp[b[i]]++;
    }
    for (int i=1;i<=n;i++) {
        if (mp[a[i]]>0) {
            mp[a[i]]--;
            res++;
        }
    }
    cout<<res;
}
