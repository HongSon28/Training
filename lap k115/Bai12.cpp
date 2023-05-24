#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned n;
    unsigned tong=0;
    cin>>n;
    for (unsigned i=2;i<=n; i++ ) {
        while (n%i==0) {
            cout<<i<<" ";
            n=n/i;
            tong=tong+i;
        }
    }
    cout<<endl<<tong;
}
