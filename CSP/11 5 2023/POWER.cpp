#include<bits/stdc++.h>
using namespace std;
long long a,n,m;
long long power(long long x, long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%m;
    if (n%2==0) {
        long long res=temp*temp;
        res%=m;
        return res;
    } else {
        long long res=((x%m)*temp)%m*temp;
        res%=m;
        return res;
    }
}
int main() {
    freopen("POWER.INP","r",stdin);
    freopen("POWER.OUT","w",stdout);
    cin>>a>>n>>m;
    cout<<power(a,n);
}
