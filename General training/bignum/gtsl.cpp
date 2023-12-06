#include<bits/stdc++.h>
using namespace std;
#define bignum_vec vector<int>
void xuat(bignum_vec a) {
    for (int i=a.size()-1;i>=0;i--) cout<<a[i];
}
bignum_vec operator * (bignum_vec a, long long b)
{
    bignum_vec res;
    int rem=0;
    for (int i=0;i<a.size();i++) {
        int x=a[i]*b+rem;
        rem=x/10;
        res.push_back(x%10);
    }
    while (rem!=0) {
        res.push_back(rem%10);
        rem/=10;
    }
    return res;
}
int main() {
    bignum_vec res={1};
    int n;
    cin>>n;
    for(long long i=2;i<=n;i++) {
        res=res*i;
    }
    xuat(res);
}
