#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N+5][N+5];
int m,n,k;
int red,blue;
void change1(int x,int y) {
    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            if (a[i][j]==0) a[i][j]=1;
            else if (a[i][j]==1) a[i][j]=1;
            else if (a[i][j]==2) a[i][j]=0;
        }
    }
}
void change2(int x,int y) {
    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            if (a[i][j]==0) a[i][j]=2;
            else if (a[i][j]==1) a[i][j]=0;
            else if (a[i][j]==2) a[i][j]=2;
        }
    }
}
int main() {
    cin>>n>>m>>k;
    while (k--) {
        int x,y;
        cin>>x>>y;
        change1(x,y);
        cin>>x>>y;
        change2(x,y);
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j]==1) red++;
            else if(a[i][j]==2) blue++;
        }
    }
    cout<<red<<' '<<blue;
}
