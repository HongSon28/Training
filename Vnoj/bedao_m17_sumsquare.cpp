#include<bits/stdc++.h>
using namespace std;
long long x;
long long res;
int main() {
    cin>>x;
    for (long long i=1;i*i<=x;i++) {
        long long m=i*i;
        long long n=x-m;
        long long j=sqrt(n);
        if (j*j==n) {
            res++;
        }
    }
    cout<<res;
}
