#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,t;
long long a[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    while (q--) {
        cin>>t;
        long long res=0,c1=0,c2=0;
        for (long long i=1;i*i<=a[t];i++) {
            if (a[t]%i!=0) continue;
            c1=c2=0;
            long long j=a[t]/i;
            for (int k=1;k<=n;k++) {
                if (a[k]%i==0) c1++;
                if (a[k]%j==0) c2++;
            }
            if (c1>(n/10)) res=max(res,i);
            if (c2>(n/10)) res=max(res,j);
        }
        cout<<res<<'\n';
    }
}
