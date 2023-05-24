#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned a,b,c,d,x,y,z;
    unsigned dem=0;
    cin>>a>>b>>c>>d;
    if (a<b) {
        swap(a,b);
    }
    if (a<c)
        swap(a,c);
    if (b<c) {
        swap(b,c);
    }
    for (x=1;x<=(d-b-c);x++) {
        for (y=1;y<=(d-a-c);y++) {
            if ((d-(a*x+b*y))%c==0) {
                dem=dem+1;
            }
        }
    }
    cout<<dem;
}
