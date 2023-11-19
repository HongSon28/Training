#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int t[N+5],a[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("PERMUTATION.INP","r",stdin);
    freopen("PERMUTATION.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=n;i++) {
        int cnt=0;
        for (int j=1;j<=n;j++) {
            if (a[j]==0) cnt++;
            if (cnt-1==t[i]) {
                a[j]=i;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
}
