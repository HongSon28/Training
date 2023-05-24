#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int a[100000];
    int n, mx;
    int kq[t];
    for (int i=0;i<t;i++) {
        int dem=1;
        cin>>n;
        for (int j=0;j<n;j++) {
            cin>>a[j];
        }
        mx=a[0];
        for (int j=1;j<n;j++) {
            if (a[j]>=mx){
                dem+=1;
                mx=a[j];
            }
        }
        kq[i]=dem;
    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}

