#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long s[N+5],d[N+5];
long long cur;
int main() {
    freopen("ODOOR.INP","r",stdin);
    freopen("ODOOR.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i]>>d[i];
    for (int i=1;i<=n;i++) {
        if (s[i]>=cur) {
            cur=s[i]+1;
        } else {
            long long temp=(cur-s[i]+d[i]-1)/d[i];
            cur=s[i]+d[i]*temp+1;
        }
    }
    cout<<cur-1;
}
