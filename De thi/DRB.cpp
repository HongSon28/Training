#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("DRB.inp");
    ofstream out;
    out.open("DRB.out");
    unsigned long long s1,s2,v1,v2;
    inp>>s1>>v1>>s2>>v2;
    if ((s1<s2)&&(v1<v2)) {
        out<<"-1";
    } else if ((s1>s2)&&(v1>v2)) {
        out<<"-1";
    } else if ((s1<s2)&&(v1>v2)) {
        out<<(s2-s1)/(v1-v2);
    } else {
        out<<(s1-s2)/(v2-v1);
    }
    inp.close();
    out.close();
}
