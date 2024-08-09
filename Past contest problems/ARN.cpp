#include<bits/stdc++.h>
using namespace std;
bool P(unsigned x, unsigned y, unsigned z, unsigned t) {
    int dungluong=x*z;
    if (t*y>=dungluong) {
        return true;
    } else {
        return false;
    }
}
int binarySearch(unsigned x, unsigned y, unsigned z) {
    unsigned lo=1;
    unsigned hi=ceil(x*z/y);
    unsigned mid= lo+(hi-lo)/2;
    if (P(x,y,z,mid)==true)
        hi=mid;
    else
        lo=mid+1;
    return lo;
}
int main() {
    ifstream inp;
    inp.open("TBG.inp");
    ofstream out;
    out.open("TBG.out");
    unsigned x,y,z;
    inp>>x>>y>>z;
    out<<binarySearch(x,y,z);
    inp.close();
    out.close();
}
