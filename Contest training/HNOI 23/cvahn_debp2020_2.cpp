#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n;
int a[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m*n;i++) cin>>a[i];
    sort(a+1,a+1+m*n);
    for (int i=1;i<=m;i++) {
        if (i%2==0) {
            for (int j=n;j>=1;j--) cout<<a[(i-1)*n+j]<<' ';
        } else {
            for (int j=1;j<=n;j++) cout<<a[(i-1)*n+j]<<' ';
        }
        cout<<'\n';
    }
}
