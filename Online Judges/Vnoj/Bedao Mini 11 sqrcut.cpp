#include <iostream>
using namespace std;
int main () {
    unsigned t,tg;
    cin>>t;
    unsigned a[t];
    unsigned b[t];
    for (unsigned i=0;i<t;i++) {
        cin>>a[i]>>b[i];
    }
    unsigned dem=0;
    for (unsigned i=0; i<t;i++) {
        while (a[i]!=b[i]) {
            tg=b[i];
            b[i]=a[i]-b[i];
            a[i]=tg;
            if(a[i]<b[i]) {
                swap(a[i],b[i]);
            }
            dem=dem+1;
        }
        cout<<dem<<endl;
    }
}
