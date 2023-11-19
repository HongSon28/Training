#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
long long calc(long long k) {
    long long sum=0,i=1;
    while (i<=min(n,k)) {
        long long temp=min(k,n/(n/i));
        sum+=(n/i)*(temp-i+1);
        i=temp+1;
    }
    return sum;
}
int main() {
    cin>>n>>a>>b;
    cout<<calc(b)-calc(a-1);
}
