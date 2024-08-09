#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    unsigned k;
    inp>>k;
    unsigned n[k],x[k];
    for (unsigned i=0; i<k;i++) {
        inp>>n[i]>>x[i];
    }
    for (unsigned i=0; i<k;i++) {
        unsigned dem=0;
        unsigned temp=n[i];
        while (temp<=x[i]) {
            temp=temp+n[i];
            dem=dem+1;
        }
        out<<dem<<endl;
    }
    inp.close();
    out.close();
}
