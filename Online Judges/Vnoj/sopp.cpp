#include<bits/stdc++.h>
using namespace std;
int main() {
    int l,r;
    cin>>l>>r;
    int a[r+1]={};
    int dem=0;
    for (int i=1;i<r;i++) {
        for (int j=i*2;j<=r;j+=i) {
            a[j]+=i;
        }
    }
    for (int i=l;i<=r;i++) {
        if (a[i]>i)
            dem++;
    }
    cout<<dem;
}
