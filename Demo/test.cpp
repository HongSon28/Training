#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; //so luong phan tu
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int mn=a[0]; //tim min
    for (int i=1;i<n;i++) {
        if (a[i]<mn) {
            mn=a[i];
        }
    }
    cout<<mn<<endl;
    int mx=a[0]; //tim max
    for (int i=1;i<n;i++) {
        if (a[i]>mx) {
            mx=a[i];
        }
    }
    cout<<mx<<endl;
}
