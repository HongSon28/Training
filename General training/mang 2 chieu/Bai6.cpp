#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        int tong=0;
        for (int j=0;j<n;j++) {
            tong+=a[i][j];
        }
        cout<<tong<<" ";
    }
    cout<<endl;
    for (int i=0;i<m;i++) {
        int mx=-1000000;
        for (int j=0;j<n;j++) {
            mx=max(mx,a[i][j]);
        }
        cout<<mx<<" ";
    }
}
