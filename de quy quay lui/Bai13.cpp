#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
bool c[11];
int a[11];
bool check(int j) {
    if (c[j]==true)
        return true;
    return false;
}
void xuat(int tt) {
    cout<<tt<<endl;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<a[i];j++) {
            cout<<"0 ";
        }
        cout<<i<<" ";
        for (int j=a[i]+1;j<=n;j++) {
            cout<<"0 ";
        }
        cout<<endl;
    }
}
void dequy(int i) {
    for (int j=1;j<=n;j++) {
        if (check(j)==true) {
            c[j]=false;
            a[i]=j;
            if (i==n) {
                xuat(cnt);
                cnt++;
            } else {
                dequy(i+1);
            }
            c[j]=true;
        }
    }
}
int main() {
    memset(c,true,sizeof(c));
    cin>>n;
    dequy(1);
}
