#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    cin>>n;
    unsigned int buoc=0;
    while (n>1) {
        buoc=buoc+1;
        if (n%2==0) {
            n=n/2;
        } else {
            n=3*n+1;
        }
    }
    cout<<buoc;
}

