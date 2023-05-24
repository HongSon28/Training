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
    int gach1=0;
    int gach2=0;
    for (int i=0;i<=m-2;i++) {
        for (int j=0;j<=n-2;j++) {
            if ((a[i][j]==3)&&(a[i][j+1]==1)&&(a[i+1][j]==0)&&(a[i+1][j+1]==2)) {
                gach1+=1;
            }
            if ((a[i][j]==2)&&(a[i][j+1]==0)&&(a[i+1][j]==1)&&(a[i+1][j+1]==3)) {
                gach2+=1;
            }
        }
    }
    cout<<gach1<<" "<<gach2;
}
