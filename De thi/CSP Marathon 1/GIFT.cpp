#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
long long a[N+5],b[N+5];
int pos[N+5];
int main() {
    freopen("GIFT.INP","r",stdin);
    freopen("GIFT.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]%k==0) {
            cout<<i;
            return 0;
        }
        if (pos[a[i]%k]!=0) {
            int j=pos[a[i]%k];
            if (a[j]>=a[i]) cout<<j<<' '<<-i;
            else cout<<-j<<' '<<i;
            return 0;
        } else pos[a[i]%k]=i;
        b[i]=a[i]%k;
    }
    cout<<0;
}
