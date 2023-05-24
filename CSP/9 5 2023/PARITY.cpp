#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("PARITY.INP","r",stdin);
    freopen("PARITY.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        long long n;
        cin>>n;
        int c1=0,c2=0;
        while (n!=0) {
            if (n%2==0) c1++;
            else c2++;
            n/=2;
        }
        if (c1==c2) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
