#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int kq=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++) {
        if (a[i]>0) {
            for (int j=i+1;j<n;j++) {
                if (a[j]>0) {
                    kq=max(kq,j-i+1);
                } else {
                    break;
                }
            }
        }
    }
    cout<<kq<<endl;
    for (int i=0;i<=n-kq;i++) {
        int dem=0;
        for (int j=i;j<i+kq;j++) {
            if (a[j]>0)
                dem+=1;
        }
        if (dem==kq) {
            for (int j=i;j<i+kq;j++) {
                cout<<a[j]<<" ";
            }
        }
    }
}
