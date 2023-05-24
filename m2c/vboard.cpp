#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[501][501];
int s1[501][501],s2[501][501];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (i==0||j==0) {
                s1[i][j]=0;
                s2[i][j]=0;
            } else {
                if ((i+j)%2==0) {
                    s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1]+a[i][j];
                    s2[i][j]=s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1];
                } else {
                    s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
                    s2[i][j]=s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1]+a[i][j];
                }
            }
        }
    }
    cin>>q;
    for (int i=0;i<q;i++) {
        int i1,j1,i2,j2;
        cin>>i1>>j1>>i2>>j2;
        int sum1=s1[i2][j2]-s1[i2][j1-1]-s1[i1-1][j2]+s1[i1-1][j1-1];
        int sum2=s2[i2][j2]-s2[i2][j1-1]-s2[i1-1][j2]+s2[i1-1][j1-1];
        cout<<abs(sum1-sum2)<<endl;
    }
}
