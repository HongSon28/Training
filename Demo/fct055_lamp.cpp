#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c[N+5];
int n,q,x,y;
int main() {
    cin>>n>>q;
    while (q--) {
        cin>>x>>y;
        c[x]++;
        c[y+1]--;
    }
    for (int i=1;i<=n;i++) {
        c[i]+=c[i-1];
        cout<<c[i]%2<<' ';
    }
}
