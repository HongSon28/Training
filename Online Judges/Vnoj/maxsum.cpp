#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int kq=INT_MIN;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int tong=0;
            for (int k=i;k<=j;k++) {
                tong+=a[k];
            }
            if (tong>kq)
                kq=tong;
        }
    }
    cout<<kq;
}
