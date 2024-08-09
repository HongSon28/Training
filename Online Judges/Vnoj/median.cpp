#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    int a[n];
    int kq[q];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<q;i++) {
        int l,r;
        cin>>l>>r;
        int temp[r];
        for (int j=l;j<=r;j++) {
            temp[j-l]=a[j-1];
        }
        sort(temp,temp+r-l+1);
        kq[i]=temp[(r-l)/2];
    }
    for (int i=0;i<q;i++) {
        cout<<kq[i]<<endl;
    }
}
