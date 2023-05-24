#include<bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin>>m;
    int a[m][m];
    for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    int dem=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j]==a[j][i])
                dem+=1;
        }
    }
    if (dem==m*m)
        cout<<"YES";
    else
        cout<<"NO";
}
