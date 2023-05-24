#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int check() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]!=a[j][i]) return false;
        }
    }
    return true;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    if (check()==true) {
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=i;j++) {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    } else {
        cout<<"NO"<<endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i<j) cout<<a[j][i]<<' ';
                else cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
