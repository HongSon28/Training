#include<bits/stdc++.h>
using namespace std;
int main() {
    long unsigned n,du;
    unsigned tong=0;
    cin>>n;
    while (n>0) {
        du=(n%10);
        tong=tong+du;
        n=n/10;
    }
    cout<<tong;
}

