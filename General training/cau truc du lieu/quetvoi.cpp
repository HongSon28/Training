#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
struct xy{
    int x,y;
};
bool v[102][102];
int m,n,a[102][102],s,c,resa=0,resb=0;
bool check(int x, int y) {
    if (x>=1&&x<=m&&y>=1&&y<=n) return true;
    return false;
}
vector<int>vc;
void dfs(int x, int y) {
    int temp=0;
    resa++;
    stack<xy>st;
    st.push({x,y});
    v[x][y]=true;
    while (st.empty()==false) {
        x=st.top().x;
        y=st.top().y;
        st.pop();
        if (a[x][y]-a[x-1][y]>0) temp+=a[x][y]-a[x-1][y];
        if (a[x][y]-a[x+1][y]>0) temp+=a[x][y]-a[x+1][y];
        if (a[x][y]-a[x][y-1]>0) temp+=a[x][y]-a[x][y-1];
        if (a[x][y]-a[x][y+1]>0) temp+=a[x][y]-a[x][y+1];
        for (int i=0;i<4;i++) {
            if (v[x+dx[i]][y+dy[i]]==false&&check(x+dx[i],y+dy[i])==true&&a[x+dx[i]][y+dy[i]]>0) {
                v[x+dx[i]][y+dy[i]]=true;
                st.push({x+dx[i],y+dy[i]});
            }
        }
    }
    vc.push_back(temp);
    resb+=temp;
}
int main() {
    memset(v,false,sizeof(v));
    cin>>m>>n;
    fill(&a[0][0], &a[0][0]+102,0);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]>=1&&v[i][j]==false) {
                dfs(i,j);
            }
        }
    }
    cout<<resa<<endl<<resb<<endl;
    int mx=0,in;
    for (int i=0;i<vc.size();i++) {
        if (mx<vc[i]) {
            mx=vc[i];
            in=i+1;
        }
    }
    cout<<in<<' '<<mx;
}
