#include<iostream>
using namespace std;
int main() {
    unsigned n;
    int tong=0;
    cin>>n;
    int a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    for (unsigned i=1;i<n;i+=2) {
        tong+=a[i];
    }
    cout<<tong;
}
