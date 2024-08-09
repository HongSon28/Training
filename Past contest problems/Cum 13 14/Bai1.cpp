#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int t=__gcd(a,b);
    a/=t,b/=t;
    if (b<0) {
        b=-b;
        a=-a;
    }
    cout<<a<<' '<<b;
}
