#include<bits/stdc++.h>
using namespace std;
bool check(long long n) {
    if (n<=1) return false;
    for (long long i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}
long long n;
int main() {
    cin>>n;
    long long sq=sqrt(n);
    if (sq*sq!=n) sq++;
    while (!check(sq)) sq++;
    cout<<sq*sq;
}
