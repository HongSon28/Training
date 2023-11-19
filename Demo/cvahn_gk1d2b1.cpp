#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],c[N*2+5];
int res[N+5];
int cnt;
int main() {
    freopen("MOTLAN.INP","r",stdin);
    freopen("MOTLAN.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]+N]++;
    }
    for (int i=1;i<=n;i++) {
        if (c[a[i]+N]==1) {
            cnt++;
            res[cnt]=a[i];
        }
    }
    sort(res+1,res+1+cnt);
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;i++) cout<<res[i]<<' ';
}
