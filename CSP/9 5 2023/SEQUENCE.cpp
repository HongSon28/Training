#include<bits/stdc++.h>
using namespace std;
long long x,n,m;
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
long long rec(long long x,long long n) {
    long long res;
    if (n==1) return 1;
    if (n%2==0) return ((rec((x%m*x%m)%m,n/2))*((x%m+1)%m))%m;
    else res=((rec((x%m*x%m)%m,n/2))*((x%m+1)%m)+power(x,n-1))%m;
    return res;
}
int main() {
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    cin>>x>>n>>m;
    n++;
    cout<<rec(x,n);
}
