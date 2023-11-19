#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
pair<int,int>a[N+5];
int n;
int mn=INT_MAX,mx=INT_MIN;
int main() {
    freopen("MAXSEG.INP","r",stdin);
    freopen("MAXSEG.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
        mn=min(mn,a[i].first);
        mx=max(mx,a[i].second);
    }
    for (int i=1;i<=n;i++) {
        if (a[i].first<=mn&&a[i].second>=mx) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}
