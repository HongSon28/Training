#include<bits/stdc++.h>
using namespace std;
int n,q;
int main() {
    freopen("GOAT.INP","r",stdin);
    freopen("GOAT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>q;
    while (q--) {
        cin>>n;
        if (n%10==0) cout<<"BOBO"<<'\n';
        else cout<<"SIUU"<<'\n';
    }
}
