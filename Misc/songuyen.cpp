#include<bits/stdc++.h>
using namespace std;
int main() {
    int l,r,a,b,sd,sc;
    int tong=0;
    cin>>l>>r>>a>>b;
    if (a%l==0) {
        sd=a;
    } else if (l%a==0) {
        sd=l;
    } else {
        sd=(l/a+1)*a;
    }
    if (r%a==0) {
        sc=r;
    } else {
        sc=(r/a)*a;
    }
    tong+=(sc-sd)/a+1;
    if (b%l==0) {
        sd=b;
    } else if (l%b==0) {
        sd=l;
    } else {
        sd=(l/b+1)*b;
    }
    if (r%b==0) {
        sc=b;
    } else {
        sc=(r/b)*b;
    }
    tong+=(sc-sd)/b+1;
    int bcnn=a * b / __gcd(a, b);
    if (bcnn%l==0) {
        sd=bcnn;
    } else if (l%bcnn==0) {
        sd=l;
    } else {
        sd=(l/bcnn+1)*bcnn;
    }
    if (r%bcnn==0) {
        sc=bcnn;
    } else {
        sc=(r/bcnn)*bcnn;
    }
    tong-=(sc-sd)/bcnn+1;
    cout<<tong;

}

