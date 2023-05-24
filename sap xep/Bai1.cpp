#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,h;
    cin>>n>>h;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int vt=0,nhom=1;
    for (int i=1;i<n;i++) {
        if (a[i]-a[vt]>h) {
            nhom++;
            vt=i;
        }
    }
    cout<<nhom;
}
