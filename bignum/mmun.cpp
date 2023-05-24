#include<bits/stdc++.h>
using namespace std;
#define bignum_vec vector<int>
void xuat(bignum_vec a) {
    for (int i=a.size()-1;i>=0;i--) cout<<a[i];
}
bignum_vec operator * (bignum_vec a, bignum_vec b)
{
    bignum_vec product(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
        {
            product[i + j] += (a[i] * b[j]);
            product[i + j + 1] += (product[i + j] / 10);
            product[i + j] %= 10;
        }
    while(product[product.size()-1]==0) product.pop_back();
    return product;
}
int main() {
    bignum_vec m;
    string s;
    cin>>s;
    for (int i=s.size()-1;i>=0;i--) {
        int x=(int)s[i]-48;
        m.push_back(x);
    }
    bignum_vec res=m;
    long long n;
    cin>>n;
    for (int i=2;i<=n;i++) {
        res=res*m;
    }
    xuat(res);
}

