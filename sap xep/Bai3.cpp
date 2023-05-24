#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int dem=0,j=0;
    while (dem==0) {
        int ct=1;
        while (a[j]==a[j+1]) {
            ct++;
            j++;
        }
        if (ct%2!=0) {
            dem++;
            cout<<a[j];
        } else {
            j++;
        }
    }
    if (dem==0)
        cout<<"0";
}
