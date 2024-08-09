#include<bits/stdc++.h>
using namespace std;
int goc(int a, int b) {
    while (a!=b) {
        if (a>b) {
            if (a%2==0) {
                a/=2;
            } else {
                a=(a-1)/2;
            }
        } else {
            if (b%2==0) {
                b/=2;
            } else {
                b=(b-1)/2;
            }
        }
    }
    return a;
}
int main() {
    int t;
    cin>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        int u,v;
        cin>>u>>v;
        kq[i]=goc(u,v);
    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}
