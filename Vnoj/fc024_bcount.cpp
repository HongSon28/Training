#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
int c[N+5][4];
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[i][1]=c[i-1][1];
        c[i][2]=c[i-1][2];
        c[i][3]=c[i-1][3];
        c[i][a[i]]++;
    }
    while (q--) {
        int a,b;
        cin>>a>>b;
        cout<<c[b][1]-c[a-1][1]<<' '<<c[b][2]-c[a-1][2]<<' '<<c[b][3]-c[a-1][3]<<'\n';
    }
}
