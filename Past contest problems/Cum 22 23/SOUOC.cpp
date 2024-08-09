#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int k,q;
int c[N+1]={};
int prefix[N+1]={};
void sang() {
    for (int i=1;i<=N;i++) {
        for (int j=i;j<=N;j+=i) {
            c[j]++;
        }
    }
    for (int i=1;i<=N;i++) {
        if (c[i]>=k) {
            prefix[i]=prefix[i-1]+1;
        } else {
            prefix[i]=prefix[i-1];
        }
    }
}
int main() {
    freopen("SOUOC.INP","r",stdin);
    freopen("SOUOC.OUT","w",stdout);
    cin>>k>>q;
    sang();
    while (q--) {
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
}
