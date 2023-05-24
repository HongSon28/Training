#include<iostream>
using namespace std;
int main() {
    unsigned t;
    cin>>t;
    long unsigned a[t];
    for (unsigned i=0;i<t;i++) {
        cin>>a[i];
    }
    for (unsigned i=0;i<t;i++) {
        cout<<a[i]/2+1<<endl;
    }
}
