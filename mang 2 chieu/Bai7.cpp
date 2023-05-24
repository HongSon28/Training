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
    int dem=0;
    for (int i=0;i<m;i++) {
        int mx=-1000000;
        int diemj,diemi;
        for (int j=0;j<n;j++) {
            if (a[i][j]>mx) {
                mx=a[i][j];
                diemj=j;
            }
        }
        int mn=1000000;
        for (int k=0;k<m;k++) {
            if (a[k][diemj]<mn) {
                mn=a[k][diemj];
                diemi=k;
            }
        }
        if (mn==mx) {
            cout<<diemi+1<<" "<<diemj+1;
            dem+=1;
            break;
        }
    }
    if (dem==0) {
        cout<<"0";
    }
}
