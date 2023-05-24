#include<iostream>
using namespace std;
int main() {
    unsigned n;
    cin>>n;
    unsigned a[n];
    for (unsigned i=0; i<n;i++) {
        cin>>a[i];
    }
    unsigned kq=1;
    unsigned f[n];
    for (unsigned i=0; i<n; i++) {
        f[i]=0;
        for (int j=i-1;j>=0;j--) {
            if (a[j]<a[i]) {
                f[i]=max(f[i],f[j]);
            }
        }
        f[i]+=1;
        kq=max(kq,f[i]);
    }
    cout<<kq;
}
