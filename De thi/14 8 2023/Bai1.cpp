#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main() {
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        int sq=sqrt(n);
        for (int i=sq;i>=1;i--) {
            if (n%(i*i)==0) {
                cout<<i<<' '<<n/i/i<<'\n';
                break;
            }
        }
    }
}
