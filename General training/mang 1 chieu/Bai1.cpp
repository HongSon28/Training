#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int dem=0;
    int tong=0;
    cin>>n;
    int a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    for (unsigned i=0;i<n;i++) {
        if (a[i]>0) {
            dem+=1;
            tong+=a[i];
        }
    }
    cout<<dem<<" "<<tong;
}
