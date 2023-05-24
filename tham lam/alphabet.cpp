#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int ii=1;ii<=t;ii++) {
        int n;
        cin>>n;
        char c[n+2][n+2];
        char res[n+2][n+2];
        for (int i=0;i<=n+1;i++) {
            for (int j=0;j<=n+1;j++) {
                c[i][j]='.';
                res[i][j]='.';
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cin>>c[i][j];
            }
        }
        for (int i=1;i<=n;i++) {
             for (int j=1;j<=n;j++) {
                if (c[i][j]!='.') {
                    res[i][j]=c[i][j];
                }
                else {
                    res[i][j]='A';
                    while (res[i][j]==c[i+1][j]||res[i][j]==c[i-1][j]||res[i][j]==c[i][j+1]||res[i][j]==c[i][j-1]||res[i][j]==res[i-1][j]||res[i][j]==res[i][j-1]) {
                        int temp=(int) res[i][j];
                        temp++;
                        res[i][j]=(char)temp;
                    }
                }
            }
        }
        cout<<"Case "<<ii<<':'<<endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout<<res[i][j];
            }
            cout<<endl;
        }
    }
}
