#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int a[N+5];
pair<int,int>p[N+5];
vector<int>b(N+5,INT_MAX);
int res;
int main() {
    //freopen("GRSORT.INP","r",stdin);
    //freopen("GRSORT.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) a[p[i].second]=(i+k-1)/k;
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i]-1;
        res=max(res,k);
    }
    cout<<n-res;
}

