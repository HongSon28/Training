#include<bits/stdc++.h>
using namespace std;
int m,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m;
    while (m--) {
        cin>>n;
        if (n%2==0||n%5==0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
