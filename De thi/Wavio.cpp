#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    unsigned a[100]={};
    unsigned dem;
    for (unsigned i=0;i<100;i++) {
        inp>>a[i];
        if (a[i]==0) {
            dem=i;
            break;
        }
    }
    for (unsigned i=0; i<= dem; i++) {
        out<<a[i];
    }
    inp.close();
    out.close();
}
