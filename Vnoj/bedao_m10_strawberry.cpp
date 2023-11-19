#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long x;
long long a[N+5];
long long res;
long long calc(long long m) {
    return (m+1)*m/2;
}
int main() {
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        long long k=x/a[i];
        if (x%a[i]==0) k--;
        res+=a[i]*calc(k);
    }
    cout<<res;
}
