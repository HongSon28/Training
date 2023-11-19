#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
int a[N+5];
vector<int>p(N+1),b(N+1,INT_MAX);
int res;
int main() {
    freopen("LIS1.INP","r",stdin);
    freopen("LIS1.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        p[k]=i;
        res=max(res,k);
    }
    cout<<res;
    //for (int i=1;i<=res;i++) cout<<p[i]<<' ';
}
