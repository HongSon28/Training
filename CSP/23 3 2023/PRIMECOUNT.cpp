#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool check(int n) {
    if(n<2) return false;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}
bool p[N+1];
int main() {
    freopen("PRIMECOUNT.INP","r",stdin);
    freopen("PRIMECOUNT.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        int l,r,cnt=0;
        cin>>l>>r;
        while (check(l)==false) l++;
        memset(p,true,sizeof(p));
        for (int i=2;i*i<=r;i++) {
            if (l<i&&i<=r&&check(i)==true) {
                cnt++;
                //cout<<i<<' ';
            }
            for (int j=l/i*i+i;j<=r;j+=i) {
                p[j-l]=false;
            }
        }
        for (int i=l;i<=r;i++) {
            if (p[i-l]==true) {
                //cout<<i<<' ';
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
