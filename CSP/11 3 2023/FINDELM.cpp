#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("FINDELM.INP","r",stdin);
    //freopen("FINDELM.OUT","w",stdout);
    long long n;
    cin>>n;
    if (n%2==1) {
        n/=2;
        cout<<n*5+1;
    } else {
        n/=2;
        n--;
        cout<<n*5+3;
    }
}
