#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
struct xy{
    int x,y;
};
int m,n,a[102][102],s,c,ress=0,resc=0;
void dfs(int x, int y) {
    stack<xy>st;
    st.push({x,y});
    a[x][y]=2;
    while (st.empty()==false) {
        x=st.top().x;
        y=st.top().y;
        st.pop();
        if (a[x+1][y]==0)c++;
        if (a[x-1][y]==0)c++;
        if (a[x][y+1]==0)c++;
        if (a[x][y-1]==0)c++;
        for (int i=0;i<4;i++) {
            if (a[x+dx[i]][y+dy[i]]==1) {
                s++;
                a[x+dx[i]][y+dy[i]]=2;
                st.push({x+dx[i],y+dy[i]});
            }
        }
    }
}
int main() {
    cin>>m>>n;
    fill(&a[0][0], &a[0][0]+102,0);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==1) {
                s=1;
                c=0;
                dfs(i,j);
                ress=max(s,ress);
                resc=max(c,resc);
            }
        }
    }
    cout<<ress<<' '<<resc;
}
