#include<bits/stdc++.h>
using namespace std;
#define bignum_vec vector<int>
void xuat(bignum_vec a) {
    for (int i=a.size()-1;i>=0;i--) cout<<a[i];
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
    bignum_vec a,b;
    string s1,s2;
    cin>>s1>>s2;
    for (int i=s1.size()-1;i>=0;i--) {
        int x=(int)s1[i]-48;
        a.push_back(x);
    }
    for (int i=s2.size()-1;i>=0;i--) {
        int x=(int)s2[i]-48;
        b.push_back(x);
    }
    xuat(a*b);
}
