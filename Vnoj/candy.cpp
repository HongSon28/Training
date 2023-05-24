#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n;
    cin>>n;
    unsigned a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    unsigned kq=4294967295;
    for (unsigned i=0;i<n;i++) {
        unsigned tong1=0;
        unsigned tong2=0;
        for (unsigned j=0;j<=i;j++) {
            tong1+=a[j];
        }
        for (unsigned k=i+1;k<n;k++) {
            tong2+=a[k];
        }
        if (tong1>tong2) {
            kq=min(tong1-tong2,kq);
        } else if (tong1<tong2) {
            kq=min(tong2-tong1,kq);
        } else {
            kq=0;
            break;
        }
    }
    cout<<kq;
}
