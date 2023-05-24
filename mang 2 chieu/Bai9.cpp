#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n,m1,n1;
    cin>>m>>n>>m1>>n1;
    int a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int kq1,kq2;
    int mx=-1000000;
    for (int i=0;i<=m-m1;i++) {
        for (int j=0;j<=n-n1;j++) {
            int tong=0;
            for (int p=i;p<i+m1;p++) {
                for (int q=j;q<j+n1;q++) {
                    tong+=a[p][q];
                }
            }
            if(tong>mx) {
                mx=tong;
                kq1=i+1;
                kq2=j+1;
            }
        }
    }
    cout<<mx<<endl;
    cout<<kq1<<" "<<kq2;
}
