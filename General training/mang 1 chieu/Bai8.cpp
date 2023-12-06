#include<bits/stdc++.h>
int demcs(int a, int k) {
    if ((a==0)&(k==0)) {
        return 1;
    }
    int dm=0;
    while (a!=0) {
        if (a%10==k) {
            dm+=1;
        }
        a/=10;
    }
    return dm;
}
using namespace std;
int main() {
    int t;
    cin>>t;
    int n,k;
    int a[1000];
    int b[t];
    for (int i=0; i<t; i++) {
        int kq=0;
        cin>>n>>k;
        for (int j=0; j<n; j++) {
            cin>>a[j];
        }
        for (int j=0; j<n; j++) {
            kq+=demcs(a[j],k);

        }
        b[i]=kq;
    }
    for (int i=0; i<t; i++) {
        cout<<b[i]<<endl;
    }
}
