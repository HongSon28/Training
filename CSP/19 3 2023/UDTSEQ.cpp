#include<bits/stdc++.h>
using namespace std;
const long long N=1e5;
long long n,m;
long long a[N+5],b[N+5];
int main() {
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    cin>>n>>m;
    while (m--) {
        int i,j,k;
        cin>>i>>j>>k;
        b[i]+=k;
        b[j+1]-=k;
    }
    long long sum=0;
    for (int i=1;i<=n;i++) {
        sum+=b[i];
        cout<<sum<<' ';
    }
}
