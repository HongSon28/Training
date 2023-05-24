#include<bits/stdc++.h>
using namespace std;
int n,x,y,d=1;
int c[9][9];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
void xuat() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    exit(0);
}
void dequy(int x,int y) {
    for (int i=0;i<8;i++) {
        if (x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=n&&c[x+dx[i]][y+dy[i]]==0) {
            d++;
            c[x+dx[i]][y+dy[i]]=d;
            if (d==n*n) {
                xuat();
            } else {
                dequy(x+dx[i],y+dy[i]);
            }
            d--;
            c[x+dx[i]][y+dy[i]]=0;
        }
    }
}
int main() {
    cin>>n>>x>>y;
    memset(c,0,sizeof(c));
    c[x][y]=1;
    dequy(x,y);
}
