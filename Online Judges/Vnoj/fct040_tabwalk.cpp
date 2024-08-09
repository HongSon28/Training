#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    long long x,y;
    cin>>n;
    for (long long i=1;i*i<=n;i++) {
        if (n%i==0) {
            x=i;
            y=n/i;
        }
    }
    cout<<x-1+y-1;
}
