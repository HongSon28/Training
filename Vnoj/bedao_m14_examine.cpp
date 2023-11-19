#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int t;
long long n,res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        res=0;
        for (long long i=1,j;i*i<=n;i++) {
            if (n%i!=0) continue;
            j=n/i;
            if (__gcd(i,j)==1) {
                res+=i+j;
                res%=mod;
            }
        }
        res*=(n%mod);
        cout<<res%mod<<'\n';
    }
}
