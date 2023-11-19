#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long c[N+5];
int l,r;
double mx=1e9;
int res;
void seive() {
    for (long long i=1;i<=N;i++) {
        for (long long j=i*2;j<=N;j+=i) c[j]+=i;
    }
}
int main() {
    freopen("NTRIVIAL.INP","r",stdin);
    freopen("NTRIVIAL.OUT","w",stdout);
    seive();
    cin>>l>>r;
    for (int i=l;i<=r;i++) {
        double temp=(double)c[i]/(double)i;
        if (temp<mx) {
            mx=temp;
            res=i;
        }
    }
    cout<<res;
}
