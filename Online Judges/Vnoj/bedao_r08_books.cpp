#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
int cur;
vector<pair<int,int>>v;
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) a[i]=n-i;
    cur=n+1;
    while (q--) {
        int x;
        cin>>x;
        a[x]=cur;
        cur++;
    }
    for (int i=1;i<=n;i++) v.push_back({a[i],i});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (auto i:v) cout<<i.second<<endl;
}
