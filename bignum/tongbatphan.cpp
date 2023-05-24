#include<bits/stdc++.h>
#define bignum_vec vector<int>
using namespace std;
void xuat(bignum_vec a) {
    for (int i=a.size()-1;i>=0;i--) cout<<a[i];
}
bignum_vec operator + (bignum_vec a, bignum_vec b) {
    int rem=0;
    bignum_vec res;
    for (int i=0;i<a.size();i++) {
        int x=a[i]+b[i]+rem;
        rem=x/8;
        x%=8;
        res.push_back(x);
    }
    if (rem!=0) res.push_back(rem);
    return res;
}
int main() {
    string a,b;
    cin>>a>>b;
    while (a.size()<b.size()) a='0'+a;
    while (a.size()>b.size()) b='0'+b;
    bignum_vec n,m;
    for (int i=a.size()-1;i>=0;i--) {
        int x=(int)a[i]-48;
        n.push_back(x);
    }
    for (int i=b.size()-1;i>=0;i--) {
        int x=(int)b[i]-48;
        m.push_back(x);
    }
    xuat(n+m);
}
