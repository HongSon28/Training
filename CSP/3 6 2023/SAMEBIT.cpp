#include<bits/stdc++.h>
using namespace std;
long long m=123456789*3;
unsigned long long power(unsigned long long x, unsigned long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%m;
    if (n%2==0) {
        unsigned long long res=temp*temp;
        res%=m;
        return res;
    } else {
        unsigned long long res=((x%m)*temp)%m*temp;
        res%=m;
        return res;
    }
}
int main() {
    //freopen("SAMEBIT.INP","r",stdin);
    //freopen("SAMEBIT.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        unsigned long long n;
        cin>>n;
        if (n%2==0) {
            unsigned long long k=n/2;
            unsigned long long temp=(power(4,k)-1+m)%m;
            cout<<temp/3<<endl;
        } else {
            unsigned long long k=n/2;
            unsigned long long temp=(power(4,k)-1+m)%m;
            cout<<(temp/3*2)%123456789<<endl;
        }
    }
}
