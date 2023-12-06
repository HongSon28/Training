#include <bits/stdc++.h>
using namespace std;
int an2 (unsigned a, unsigned b, unsigned c) {
    unsigned x, y;
    unsigned dem=0;
    if (a>=b) {
        for ( x=1; x<=((c-b)/a);x++) {
            if ((c-a*x)%b==0) {
                dem=dem+1;
            }
        }
    } else {
        for ( y=1; y<=((c-a)/b);y++) {
            if ((c-b*y)%a==0) {
                dem=dem+1;
            }
        }
    }
    return dem;
}
int main() {
    long unsigned a,b,c,d;
    unsigned dem=0;
    cin>>a>>b>>c>>d;
    for (unsigned x=1;x<=((d-b-c)/a);x++) {
        dem=dem + an2(b,c,d-a*x);
    }
    cout<<dem;
}
