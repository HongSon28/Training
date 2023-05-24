#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int n;
    int kq[t];
    int a[1000];
    for (int i=0;i<t;i++) {
        cin>>n;
        int tong1=0;
        int tong2=0;
        for (int j=0;j<n;j++) {
            cin>>a[j];
        }
        for (int j=0;j<n/2;j++) {
            tong1+=a[j];
        }
        for (int j=n/2;j<n;j++) {
            tong2+=a[j];
        }
        kq[i]=tong1*tong2;
    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}
