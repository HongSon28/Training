#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n,r,c;
    while (cin>>m>>n>>r>>c) {
        int res=0;
        bool flag=true;
        if (m==0&&n==0&&r==0&&c==0) break;
        char a[m][n],b[m][n];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                cin>>a[i][j];
                b[i][j]='0';
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (a[i][j]!=b[i][j]&&i+r<=m&&j+c<=n) {
                    res++;
                    //cout<<a[i][j]<<' '<<b[i][j]<<endl;
                    for (int p=i;p<i+r;p++) {
                        for (int q=j;q<j+c;q++) {
                            //cout<<p<<' '<<q<<endl;
                            if (b[p][q]=='0') b[p][q]='1';
                            else b[p][q]='0';
                        }
                    }
                } else if (a[i][j]!=b[i][j]){
                    flag=false;
                }
            }
        }
        if (flag==false)cout<<-1<<endl;
        else cout<<res<<endl;
    }
}
