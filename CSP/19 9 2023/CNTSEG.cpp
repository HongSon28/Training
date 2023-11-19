#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
map<int,int>cnt;
int res,pos;
int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CNTSEG.INP","r",stdin);
    freopen("CNTSEG.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==m) pos=i;
    }
    for (int i=pos-1;i>=1;i--) {
        if (a[i]>m) t++;
        else t--;
        cnt[t]++;
    }
    cnt[0]++;
    t=0;
    res+=cnt[0];
    for (int i=pos+1;i<=n;i++) {
        if (a[i]>m) t++;
        else t--;
        res+=cnt[-t];
    }
    cout<<res;
}
