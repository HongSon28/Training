#include<bits/stdc++.h>
using namespace std;
unsigned long long m=20122007;
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
    freopen("NFREAK.INP","r",stdin);
    freopen("NFREAK.OUT","w",stdout);
    unsigned long long a,res=1;
    cin>>a;
    for (unsigned long long i=1;i*i<a;i++) {
        if (a%i==0) {
            res=multiple(res,power(3,i)-1)%m;
            res=multiple(res,power(3,a/i)-1)%m;
        }
    }
    unsigned long long sq=sqrt(a);
    if (sq*sq==a) res=multiple(res,power(3,sq)-1)%m;;
    cout<<res;
}
