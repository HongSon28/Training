#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,res;
int a[N+5];
vector<int>b(N+5,INT_MAX);
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res=max(res,k);
    }
    for (int i=1;i<N+5;i++) b[i]=INT_MAX;
    b[0]=INT_MIN;
    for (int i=n;i>=1;i--) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res=max(res,k);
    }
    cout<<n-res;
}
