#include<bits/stdc++.h>
using namespace std;
long long lt (long long a, long long b) {
    long long res=1;
    for (int i=1;i<=b;i++) res*=a;
    return res;
}
int main() {
    freopen("COUNTZERO.INP","r",stdin);
    freopen("COUNTZERO.OUT","w",stdout);
    long long n;
    cin>>n;
    long long k=1,dem=0;
    while (lt(5,k)<=n) {
        dem+=n/lt(5,k);
        k++;
    }
    cout<<dem;
}

