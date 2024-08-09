#include<iostream>
using namespace std;
int main() {
    unsigned a,b,c,n;
    cin>>a>>b>>c>>n;
    int tong=a-c+b;
    if ((c>a)||(c>b)||(c>n)) {
        cout<<"-1";
    } else if (tong>=n) {
        cout<<"-1";
    } else {
        cout<<n-tong;
    }
}
