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
        rem=x/10;
        x%=10;
        res.push_back(x);
    }
    if (rem!=0) res.push_back(rem);
    return res;
}
bignum_vec operator * (bignum_vec a, bignum_vec b)
{
    bignum_vec product(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
        {
            product[i + j] += (a[i] * b[j]);
            product[i + j + 1] += (product[i + j] / 10);
            product[i + j] %= 10;
        }
    while(product[product.size()-1]==0) product.pop_back();
    return product;
}
int main() {
    int n,m;
    cin>>n>>m;
    bignum_vec a={1};
    bignum_vec b={1};
    bignum_vec hai={2};
    bignum_vec ba={3};
    for (int i=0;i<n;i++) {
        a=a*hai;
    }
    for (int i=0;i<m;i++) {
        b=b*ba;
    }
    while (a.size()<b.size()) a.push_back(0);
    while (a.size()>b.size()) b.push_back(0);
    bignum_vec res=a+b;
    cout<<res[res.size()-1];
}

