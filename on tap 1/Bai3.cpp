#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long mx=1;
    while (n%2==0) {
        mx=2;
        n/=2;
    }
    while (n%3==0) {
        mx=3;
        n/=3;
    }
    for (int i=5;i<=sqrt(n);i+=6) {
        while (n%i==0) {
            mx=i;
            n=n/i;
        }
        while (n%(i+2)==0) {
            mx=i+2;
            n=n/(i+2);
        }
    }
    if (n>4)
        mx=n;
    cout<<mx;
}
