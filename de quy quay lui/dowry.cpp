#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
int a[N+5][N+5];
int sum[N+5][N+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    if (sum[n][m]%3!=0) {
        cout<<"NO";
        return 0;
    }
    int val=sum[n][m]/3;
    for (int i=1;i<n;i++) {
        int land1=sum[i][m];
        if (land1==val) {
            for (int j=1;j<m;j++) {
                int land2=sum[n][j]-sum[i][j];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"N "<<i<<endl;
                    cout<<"D "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    for (int j=1;j<m;j++) {
        int land1=sum[n][j];
        if (land1==val) {
            for (int i=1;i<n;i++) {
                int land2=sum[i][m]-sum[i][j];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"D "<<j<<endl;
                    cout<<"N "<<i<<endl;
                    return 0;
                }
            }
        }
    }
    for (int i=1;i<n;i++) {
        int land1=sum[i][m];
        if (land1==val) {
            for (int j=i+1;j<n;j++) {
                int land2=sum[j][m]-sum[i][m];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"N "<<i<<endl;
                    cout<<"N "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    for (int j=1;j<m;j++) {
        int land1=sum[n][j];
        if (land1==val) {
            for (int i=j+1;i<m;i++) {
                int land2=sum[n][i]-sum[n][j];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"D "<<j<<endl;
                    cout<<"D "<<i<<endl;
                    return 0;
                }
            }
        }
    }
    for (int i=n;i>1;i--) {
        int land1=sum[n][m]-sum[i-1][m];
        if (land1==val) {
            for (int j=1;j<m;j++) {
                int land2=sum[i-1][j];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"N "<<i-1<<endl;
                    cout<<"D "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    for (int j=m;j>1;j--) {
        int land1=sum[n][m]-sum[n][j-1];
        if (land1==val) {
            for (int i=1;i<n;i++) {
                int land2=sum[i][j-1];
                if (land2==val) {
                    cout<<"YES"<<endl;
                    cout<<"D "<<j-1<<endl;
                    cout<<"N "<<i<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
}
