#include<bits/stdc++.h>
using namespace std;
const int N=700;
int n;
long long h[N+5][N+5],v[N+5][N+5];
double t[N+5][N+5][4];
int type[N+5][N+5][4];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool check(int x,int y) {
    if (x>=1&&y>=1&&x<=n&&y<=n) return true;
    return false;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>h[i][j];
    for(int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>v[i][j];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=0;k<4;k++) {
                int x=i+dx[k],y=j+dy[k];
                if (!check(x,y)) continue;
                if (h[i][j]==h[x][y]&&v[i][j]==v[x][y]) type[i][j][k]=1;
                else if (h[i][j]<h[x][y]&&v[i][j]<v[x][y]) type[i][j][k]=2;
                else if (h[i][j]>h[x][y]&&v[i][j]>v[x][y]) type[i][j][j]=2;
                else {
                    type[i][j][k]=3;
                    t[i][j][k]=(double)abs(h[i][j]-h[x][y])/(double)abs(v[i][j]-v[x][y]);
                }
            }
        }
    }

}
