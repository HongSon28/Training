#include<bits/stdc++.h>
using namespace std;
int t;
long long m,k;
bool check(long long n) {
    if ((n+1)*n<=m*2/k) return true;
    return false;
}
int main() {
    cin>>t;
    while (t--) {
        cin>>m>>k;
        long long lo=1,hi=2e9,n=0;
        while (lo<=hi) {
            long long mid=(lo+hi)/2;
            if (check(mid)) {
                n=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        cout<<n*k+(m-k*(n+1)*n/2)/(n+1)<<endl;
    }
}
