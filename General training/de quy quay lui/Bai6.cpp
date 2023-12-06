#include<bits/stdc++.h>
using namespace std;
int n;
char a[21];
char c[2]={'A','B'};
void xuat() {
    for (int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
}
void dequy(int k) {
    for (int i=0;i<2;i++) {
        if (c[i]=='A'||(a[k-1]!='B')) {
            a[k]=c[i];
            if (k==n) {
                xuat();
            } else {
                dequy(k+1);
            }
        }
    }
}
int main() {
    a[0]='Z';
    cin>>n;
    dequy(1);
}
