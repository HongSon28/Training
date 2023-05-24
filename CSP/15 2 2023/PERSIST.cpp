#include<bits/stdc++.h>
using namespace std;
int p(int n) {
    int t=1;
    while (n>0) {
        t*=n%10;
        n/=10;
    }
    return t;
}
int main() {
    freopen("PERSIST.INP","r",stdin);
    freopen("PERSIST.OUT","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    while (n>=10) {
        cnt++;
        n=p(n);
    }
    cout<<cnt;
}
