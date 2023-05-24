#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    unsigned int dem=0;
    cin>>n;
    for (int i=2;i<=sqrt(n);i++) {
        if (n%i==0) {
            dem=dem+1;
            break;
        }
    }
    if (dem>=1) {
        cout<<"0";
    } else {
        cout<<"1";
    }
}
