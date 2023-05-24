#include<bits/stdc++.h>
using namespace std;
void sang(int n) {
    bool p[n+1];
    memset(p,true,sizeof(p));
    for (int i=2;i<=n;i++) {
        if (p[i]==true) {
            cout<<i<<' ';
            for (int j=i*2;j<=n;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("Eratos.Inp","r",stdin);
    freopen("Eratos.Out","w",stdout);
    int n;
    cin>>n;
    sang(n);
}
