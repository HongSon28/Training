#include<bits/stdc++.h>
using namespace std;
bool check (char a, char b, char c, char d) {
    if (a!=b&&a!=c&&b!=d&&c==d) return true;
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            if (check(a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1])) {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}
