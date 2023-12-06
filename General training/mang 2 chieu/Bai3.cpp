#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n,k,l;
    cin>>m>>n>>k>>l;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        swap(a[k-1][i],a[l-1][i]);
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
