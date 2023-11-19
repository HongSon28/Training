#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
long long calc(long long x) {
    return (x/2)*(x/10+1)-(5*(x/10)*(x/10+1))/2;
}
int main() {
    freopen("PAYMENT.INP","r",stdin);
    freopen("PAYMENT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        if (n==1) cout<<1;
        else if (n==2||n==3) cout<<2;
        else if (n==4) cout<<3;
        else {
            cout<<n/5+1+calc(n)+calc(n-5);
        }
        cout<<'\n';
    }
}
