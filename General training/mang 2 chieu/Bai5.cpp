#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    long long a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int cotmin=100000;
    int cot;
    for (int j=0;j<n;j++) {
        long long mx=0;
        for (int i=0;i<m;i++) {
            mx=max(mx,a[i][j]);
        }
        if (cotmin>mx) {
            cotmin=mx;
            cot=j;
        }
    }
    cout<<cot+1;
}
