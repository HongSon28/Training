#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101];
bool checknt(int x) {
    if (x<2) return false;
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) return false;
    }
    return true;
}
bool check() {
    for (int i=1;i<=n;i++) {
        int mn=a[i][1];
        int cnt=1;
        for (int j=2;j<=m;j++) {
            if (a[i][j]>mn) {
                cnt++;
                mn=a[i][j];
            }
        }
        if (cnt==m) return true;
    }
    return false;
}
int main() {
    int mx=-1;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            if (checknt(a[i][j])==true) mx=max(mx,a[i][j]);
        }
    }
    if (check()==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<mx;
}
