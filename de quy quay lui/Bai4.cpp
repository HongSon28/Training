#include<bits/stdc++.h>
using namespace std;
int m,n,d=0,res=0;
int a[16][16];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dequy(int x,int y,int last) {
    for (int i=0;i<=3,i!=last;i++) {
        int temp;
        if (i==0)
            temp=2;
        else if (i==1)
            temp=3;
        else if (i==2)
            temp=0;
        else
            temp=1;
        if (x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=n&&a[x+dx[i]][y+dy[i]]==0) {
            d++;
            if ((x+dx[i]==1||x+dx[i]==m)&&(y+dy[i]==1||y+dy[i]==n)) {
                res=max(res,d);
            } else {
                dequy(x+dx[i],y+dy[i],temp);
            }
            d--;
        }
    }
}
int main() {
    int x,y;
    cin>>m>>n>>x>>y;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    dequy(x,y,-1);
    cout<<res;
}
