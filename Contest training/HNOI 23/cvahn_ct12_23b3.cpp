#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int a[N+5];
pair<int,int>p[N+5];
vector<int>b(N+5,INT_MAX);
int res;
int main() {
    freopen("SAPXEP.INP","r",stdin);
    freopen("SAPXEP.OUT","w",stdout);
    cin>>n>>k;
    k=n/k;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p+1,p+1+n,greater<pair<int,int>>());
    for (int i=1;i<=n;i++) a[p[i].second]=(i+k-1)/k;
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int m=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[m]=a[i]-1;
        //cout<<a[i]<<' '<<m<<endl;
        res=max(res,m);
    }
    cout<<n-res;
}
