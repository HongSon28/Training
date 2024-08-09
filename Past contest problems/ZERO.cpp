#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    unsigned n;
    inp>>n;
    int a[n];
    for (unsigned i=0; i<n;i++) {
        inp>>a[i];
    }
    unsigned kq=0;
    for (unsigned i=0; i<n-1;i++) {
        for (unsigned j=i+1;j<n; j++) {
            int tong = 0;
            for (unsigned k=i;k<=j;k++) {
                tong=tong+a[k];
            }
            if (tong==0) {
                kq=max(kq,j-i);
            }
        }
    }
    out<<kq+1;
    inp.close();
    out.close();
}


