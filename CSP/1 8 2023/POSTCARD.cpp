#include<bits/stdc++.h>
using namespace std;
const int N=500;
int m,n,k,res;
int a[N+5][N+5];
int main() {
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        int c[N*N+5]={};
        int i1=i,j1=1;
        int i2=i1,j2=j1;
        c[a[i1][j1]]=1;
        int cnt=1;
        while (i1<=m&&i2<=m&&j1<=n&&j2<=n) {
            while (i2<=m&&j2<=m&&cnt<=k) {
                //cout<<i1<<' '<<j1<<' '<<i2<<' '<<j2<<' '<<cnt<<endl;
                res=max(res,i2-i1+1);
                i2++;
                j2++;
                for (int k=i1;k<=i2;k++) {
                    c[a[k][j2]]++;
                    if (c[a[k][j2]]==1) cnt++;
                }
                for (int k=j1;k<j2;k++) {
                    c[a[i2][k]]++;
                    if (c[a[i2][k]]==1) cnt++;
                }
            }
            for (int k=i1;k<=i2;k++) {
                c[a[k][j1]]--;
                if (c[a[k][j1]]==0) cnt--;
            }
            for (int k=j1+1;k<=j2;k++) {
                c[a[i1][k]]--;
                if (c[a[i1][k]]==0) cnt--;
            }
            i1++;
            j1++;
        }
    }
    for (int j=2;j<=n;j++) {
        int c[N*N+5]={};
        int i1=1,j1=j;
        int i2=i1,j2=j1;
        int cnt=1;
        c[a[i1][j1]]=1;
        while (i1<=m&&i2<=m&&j1<=n&&j2<=n) {
            while (i2<=m&&j2<=m&&cnt<=k) {
                //cout<<i1<<' '<<j1<<' '<<i2<<' '<<j2<<' '<<cnt<<endl;
                res=max(res,i2-i1+1);
                i2++;
                j2++;
                for (int k=i1;k<=i2;k++) {
                    c[a[k][j2]]++;
                    if (c[a[k][j2]]==1) cnt++;
                }
                for (int k=j1;k<j2;k++) {
                    c[a[i2][k]]++;
                    if (c[a[i2][k]]==1) cnt++;
                }
            }
            for (int k=i1;k<=i2;k++) {
                c[a[k][j1]]--;
                if (c[a[k][j1]]==0) cnt--;
            }
            for (int k=j1+1;k<=j2;k++) {
                c[a[i1][k]]--;
                if (c[a[i1][k]]==0) cnt--;
            }
            i1++;
            j1++;
        }
    }
    cout<<res;
}
