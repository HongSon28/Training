#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
long long a[N+5];
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            char t;
            cin>>t;
            if (t=='1') a[i]|=(1ll<<(j-1));
        }
        a[i]|=a[i-1];
        if (a[i]==(1ll<<m)-1) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}
