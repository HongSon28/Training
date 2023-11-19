#include<bits/stdc++.h>
using namespace std;
long long f(long long n) {
    if (n<=9) return 1;
    if (n==1000) return 1000;
    long long a=n/100,b=(n%100)/10,c=n%10;
    if (n<=99) {
        if (b==c) return 11;
        else return 10;
    }
    if (a==b&&b==c) return 111;
    if (a==b&&b!=c) return 110;
    if (a!=b&&b==c) return 100;
    if (a==c&&c!=b) return 101;
    return 102;
}
int main() {
    long long n,res=0;
    cin>>n;
    for (int i=1;i<=n;i++) {
        res+=f(i);
        //cout<<f(i)<<' ';
    }
    cout<<res;
}
