#include<bits/stdc++.h>
using namespace std;
int main() {
    long unsigned a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    long unsigned b[3];
    cin>>b[0]>>b[1]>>b[2];
    sort(b,b+3);
    if (a[0]+a[1]==a[2]) {
        cout<<"yes"<<endl;
    } else {
        cout<<"no"<<endl;
    }
    if (b[0]+b[1]==b[2]) {
        cout<<"yes"<<endl;
    } else {
        cout<<"no"<<endl;
    }
}
