#include<bits/stdc++.h>
using namespace std;
const int N=1000;
char c[N+5][N+5],a[N+5][N+5];
int m,n;
bool valid1(int i,int j) {
    return c[i-1][j-1]=='*'&&c[i-1][j+1]=='*'&&c[i][j]=='*'&&c[i+1][j-1]=='*'&&c[i+1][j+1]=='*';
}
bool valid2(int i,int j) {
    return c[i-1][j]=='*'&&c[i][j-1]=='*'&&c[i][j+1]=='*'&&c[i+1][j]=='*';
}
bool check() {
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=c[i][j])
                return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=0;i<=N+1;i++)
        for (int j=0;j<=N+1;j++)
            c[i][j]='*';
    while (cin>>m>>n) {
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                cin>>c[i][j];
                a[i][j]='.';
            }
        }
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (valid1(i,j)) {
                    a[i-1][j-1]=a[i-1][j+1]=a[i][j]=a[i+1][j-1]=a[i+1][j+1]='*';
                    //cout<<i<<' '<<j<<endl;
                }
                if (valid2(i,j)) {
                    a[i-1][j]=a[i][j-1]=a[i][j+1]=a[i+1][j]='*';
                    //cout<<i<<' '<<j<<endl;
                }
            }
        }
        if (check()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
