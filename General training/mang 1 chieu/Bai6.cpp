#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,i;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long tich=a[0];
    sort(a,a+n);
    for (int i=a[0];i>=1;i--) {
        int dem=0;
        for (int j=0;j<n;j++) {
            if (a[j]%i==0)
                dem+=1;
        }
        if (dem==n) {
            cout<<i<<endl;
            break;
        }
    }
    for (int i=1;i<n;i++) {
        tich=tich*a[i];
    }
    int temp=a[n-1];
    int bc=a[n-1];
    while (bc<=tich) {
        int dem=0;
        for (int j=0;j<n-1;j++) {
            if (bc%a[j]==0)
                dem+=1;
        }
        if (dem==n-1) {
            cout<<bc<<endl;
            break;
        } else {
            bc+=temp;
        }
    }
}
