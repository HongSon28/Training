#include<bits/stdc++.h>
using namespace std;
#define bignum_vec vector<int>
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
    freopen("TICHDOANSO.INP","r",stdin);
    freopen("TICHDOANSO.OUT","w",stdout);
    bignum_vec x;
    x.push_back(1);
    int a,b,m,n;
    cin>>a>>b>>m>>n;
    for (int i=a;i<=b;i++) {
        int temp=i;
        bignum_vec y;
        while (temp>0) {
            y.push_back(temp%10);
            temp/=10;
        }
        x=x*y;
    }
    for (int i=x.size()-1,j=m;i>=0,j>=1;i--,j--) cout<<x[i];
    cout<<' ';
    for (int i=n-1;i>=0;i--) cout<<x[i];
}

