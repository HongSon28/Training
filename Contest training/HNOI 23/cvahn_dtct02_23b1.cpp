#include<bits/stdc++.h>
using namespace std;
const int N=200;
int m,n;
int a[N+5][N+5];
int cnt,res;
int main() {
    freopen("CHEESE.INP","r",stdin);
    freopen("CHEESE.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]==1) cnt++;
        }
    }
    while (cnt!=0) {
        res++;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                int temp=0;
                if (a[i][j]==0) continue;
                if (a[i+1][j]==0) temp++;
                if (a[i][j+1]==0) temp++;
                if (a[i-1][j]==0) temp++;
                if (a[i][j-1]==0) temp++;
                if (temp>=2) {
                    a[i][j]=2;
                    cnt--;
                }
            }
        }
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (a[i][j]==2) a[i][j]=0;
            }
        }
    }
    cout<<res;
}
/*
5 6
0 0 0 0 0 0
0 1 1 0 0 0
0 1 1 1 1 0
0 1 1 1 1 0
0 0 0 0 0 0
*/
