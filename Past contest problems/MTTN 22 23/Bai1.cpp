#include<bits/stdc++.h>
using namespace std;
long long d (long long n) {
    long long res=0;
    while (n!=0) {
        res+=n%10;
        n/=10;
    }
    return res;
}
int main() {
    int t=2;
    while (t--) {
        long long n,k;
        cin>>n>>k;
        long long sum=0;
        for (long long i=k;i<=n;i+=k) {
            sum+=d(i);
        }
        cout<<sum<<endl;
    }
}
