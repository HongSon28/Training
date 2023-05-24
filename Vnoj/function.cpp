#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long n;
    long long i=1;
    cin>>n;
    long long tong=0;
    while (i<=n) {
        i+=2;
        tong-=1;
    }
    if (i<n+2) {
        tong+=n;
    }
    cout<<tong;
}
