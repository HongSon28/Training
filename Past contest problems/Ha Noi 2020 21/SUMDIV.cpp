#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("SUMDIV.INP");
    ofstream out;
    out.open("SUMDIV.OUT");
    long unsigned l,r;
    unsigned tong=0;
    inp>>l>>r;
    for (long unsigned i=1;i<=r;i++) {
        long unsigned du=r/i;
        if ((du*i<=r)&&(du*i>=l)) {
            tong=tong+i;
        }
    }
    out<<tong;
    inp.close();
    out.close();
}
