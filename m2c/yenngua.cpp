#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int minh[m],maxh[m],minc[n],maxc[n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        int mn=INT_MAX,mx=INT_MIN;
        for (int j=0;j<n;j++) {
            mn=min(a[i][j],mn);
            mx=max(a[i][j],mx);
        }
        minh[i]=mn;
        maxh[i]=mx;
    }
    for (int j=0;j<n;j++) {
        int mn=INT_MAX,mx=INT_MIN;
        for (int i=0;i<m;i++) {
            mn=min(a[i][j],mn);
            mx=max(a[i][j],mx);
        }
        minc[j]=mn;
        maxc[j]=mx;
    }
    int res=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if ((a[i][j]==minh[i]&&a[i][j]==maxc[j])||(a[i][j]==maxh[i]&&a[i][j]==minc[j])) {
                cout<<i+1<<' '<<j+1<<endl;
            }
        }
    }
}
