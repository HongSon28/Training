#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<int>b(N+5,INT_MAX);
int res;
int main() {
    freopen("INSSORT.INP","r",stdin);
    freopen("INSSORT.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i]-1;
        res=max(res,k);
    }
    cout<<n-res;
}
