#include<iostream>
using namespace std;
int main() {
    long unsigned n,c;
    cin>>n>>c;
    long unsigned a[n];
    long unsigned tong=0;
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
        tong+=a[i];
    }
    if (tong>=c) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}
