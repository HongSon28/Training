#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("CHIABA.INP","r",stdin);
    freopen("CHIABA.OUT","w",stdout);
    int a,b;
    cin>>a>>b;
    int m=b-a;
    if (m%3==0) {
        int t=m/3;
        cout<<a+t<<' '<<b-t;
    } else {
        cout<<"-1";
    }
}
