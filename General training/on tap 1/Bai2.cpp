#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long ts=a*d-c*b;
    long long ms=b*d;
    long long tg=__gcd(ts,ms);
    ts/=tg;
    ms/=tg;
    if (ms<0) {
        ms=-ms;
        ts=-ts;
    }
    cout<<ts<<" "<<ms;
}
