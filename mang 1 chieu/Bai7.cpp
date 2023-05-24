#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    int dem=0;
    unsigned long long tong=0;
    cin>>n;
    unsigned long long a[n];
    a[0]=1;
    a[1]=1;
    for (int i=2; i<n; i++) {
        a[i]=a[i-1]+a[i-2];
    }
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
        tong+=a[i];
    }
    float tb=tong/n;
    for (int i=0; i<n; i++) {
        if (a[i]>tb) {
            dem+=1;
        }
    }
    cout<<endl<<dem;
}
