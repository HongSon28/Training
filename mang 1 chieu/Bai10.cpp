#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int a[50000];
    int n,k;
    int kq[t];
    for (int i=0;i<t;i++) {
        cin>>n;
        for (int j=0;j<n;j++) {
            cin>>a[j];
        }
        cin>>k;
        sort(a,a+n);
        kq[i]=a[k-1];
    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}
