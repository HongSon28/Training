#include<bits/stdc++.h>
using namespace std;
long long n,x,res;
int main() {
    freopen("BS.INP","r",stdin);
    freopen("BS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x;
    for (int i=1;i*i<=x;i++) {
        if (x%i==0) {
            long long j=x/i;
            if (i<=n&&j<=n) {
                if (i==j) res++;
                else res+=2;
            }
        }
    }
    cout<<res;
}
