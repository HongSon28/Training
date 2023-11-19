#include<bits/stdc++.h>
using namespace std;
unsigned long long m;
unsigned long long multiple (unsigned long long a, unsigned long long b) {
    if (b==0) return 0;
    unsigned long long temp=multiple(a,b/2);
    if (b%2==0) return (temp+temp)%m;
    return ((temp+temp)%m+a%m)%m;
}
unsigned long long power(unsigned long long x, unsigned long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%m;
    if (n%2==0) {
        unsigned long long res=multiple(temp,temp);
        res%=m;
        return res;
    } else {
        unsigned long long res=multiple(multiple(x%m,temp),temp);
        res%=m;
        return res;
    }
}
int main() {
    freopen("POWEXP.INP","r",stdin);
    freopen("POWEXP.OUT","w",stdout);
    unsigned long long a,b;
    cin>>a>>b>>m;
    unsigned long long f=power(a,b),s=power(b,a);
    cout<<multiple(f,s);
}
