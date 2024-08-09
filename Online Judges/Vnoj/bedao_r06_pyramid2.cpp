#include<bits/stdc++.h>
using namespace std;
int q;
long long n,m,mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>q;
    while (q--) {
        cin>>n>>m;
        long long sum=m*m;
        sum%=mod;
        long long res=sum*n-n+1;
        cout<<res%mod<<'\n';
    }
}
