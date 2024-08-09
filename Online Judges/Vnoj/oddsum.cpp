#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long int a[n];
    long int tong=0;
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    for (unsigned i=1;i<n;i=i+2) {
        tong+=a[i];
    }
    cout<<tong;
}
