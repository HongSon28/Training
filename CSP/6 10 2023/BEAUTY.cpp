#include<bits/stdc++.h>
using namespace std;
const int N=5e3,M=1e5;
int n,res;
int a[N+5];
bool c[M*10+5];
int main() {
    freopen("BEAUTY.INP","r",stdin);
    freopen("BEAUTY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (c[a[i]+2*M-a[j]]) {
                res++;
                break;
            }
        }
        for (int j=1;j<=i;j++) c[a[i]+a[j]+2*M]=true;
    }
    cout<<res;
}
