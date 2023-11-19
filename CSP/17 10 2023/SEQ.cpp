#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
vector<int>b(N+5,INT_MAX);
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=INT_MIN;
    for (int i=n;i>=1;i--) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res=max(res,k);
    }
    cout<<res;
}
