#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1][n+1],b[n+1][n+1];
    int x=1,y=1,d=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int t=1;t<=n;t++) {
                if (i+t-1>n||j+t-1>n) break;
                cout<<i<<' '<<j<<' '<<t<<endl;
                for (int p=i;p<=i+t-1;p++) {
                    for (int q=j;q<=j+t-1;q++) {
                        b[p-i+1][q-i+1]=a[p][q];
                    }
                }
                int cnt=0;
                for (int p=1;p<=t;p++) {
                    for (int q=1;q<=t;q++) {
                        if (b[p][q]!=b[q][p]) cnt++;
                        cout<<b[p][q]<<' ';
                    }
                    cout<<endl;
                }
                cout<<cnt<<endl<<endl;
                if (k*2>=cnt) {
                    if (t>d) {
                        d=t;
                        x=i;
                        y=j;
                    }
                }
            }
        }
    }
    cout<<x<<' '<<y<<' '<<d;
}
