#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
bool check() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) {
                if (a[i][j]!=1) return false;
            } else {
                if (a[i][j]!=0) return false;
            }
        }
    }
    return true;
}
int main() {
    int cnt=0;
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]==0) cnt++;
        }
    }
    if (check()==true) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    cout<<cnt;
}
