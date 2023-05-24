#include<bits/stdc++.h>
using namespace std;
long long m,a[3];
long long multiple (long long a, long long b) {
    if (b==0) return 0;
    long long temp=multiple(a,b/2);
    if (b%2==0) return (temp+temp)%m;
    return ((temp+temp)%m+a%m)%m;
}
int main() {
    freopen("MAXPRO.INP","r",stdin);
    freopen("MAXPRO.OUT","w",stdout);
    cin>>a[0]>>a[1]>>a[2]>>m;
    sort(a,a+3);
    if (a[1]>=0) cout<<multiple(a[1],a[2]);
    else cout<<multiple(abs(a[1]),abs(a[0]));
}
