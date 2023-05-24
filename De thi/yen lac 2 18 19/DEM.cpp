#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("DEM.inp");
    ofstream out;
    out.open("DEM.out");
    unsigned n;
    inp>>n;
    unsigned giaithua=1;
    for (unsigned i=n;i>1;i--) {
        giaithua=giaithua*i;
    }
    unsigned dem=0;
    while (giaithua%10==0) {
        dem=dem+1;
        giaithua/=10;
    }
    out<<dem;
    inp.close();
    out.close();
}

