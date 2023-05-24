#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    int kq=0;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<=n-k;i++) {
        int tong=0;
        for (int j=i;j<i+k;j++) {
            tong+=a[j];
        }
        cout<<tong<<endl;
        kq=max(kq,tong);
    }
    cout<<kq;
}
