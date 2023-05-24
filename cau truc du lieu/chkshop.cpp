#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("chkshop.inp");
    ofstream out("chkshop.out");
    int n;
    inp>>n;
    int a[n],b[n];
    for (int i=0;i<n;i++) {
        inp>>a[i];
    }
    for (int i=0;i<n;i++) {
        inp>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for (int i=0;i<n;i++) {
        if (a[i]!=b[i]) {
            out<<"NO";
            return 0;
        }
    }
    out<<"YES";
}
