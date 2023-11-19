#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,res;
long long a[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (long long i=0;i<32;i++) {
        long long cnt0=0,cnt1=0;
        for (long long j=1;j<=n;j++) {
            if ((a[j]>>i&1)==0) cnt0++;
            else cnt1++;
        }
        res+=cnt0*cnt1*(1<<i);
    }
    cout<<res;
}
