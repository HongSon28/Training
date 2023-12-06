#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    unsigned int tong=0;
    cin>>n;
    for (int i=1;i<n;i++) {
        if (n%i==0) {
            tong=tong+i;
        }
    }
    if ((tong==n)&&(n!=0)) {
        cout<<"1";
    } else {
        cout<<"0";
    }
}
