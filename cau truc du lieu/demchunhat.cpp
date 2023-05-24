#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
struct xy{
    int x,y;
};
int n,a[1001][1001],mxx,mxy,mnx,mny,res=0;
void dfs(int x, int y) {
    stack<xy>st;
    st.push({x,y});
    a[x][y]=2;
    while (st.empty()==false) {
        x=st.top().x;
        y=st.top().y;
        st.pop();
        mxx=max(mxx,x);
        mxy=max(mxy,y);
        mnx=min(mnx,x);
        mny=min(mny,y);
        for (int i=0;i<4;i++) {
            if (a[x+dx[i]][y+dy[i]]==1) {
                a[x+dx[i]][y+dy[i]]=2;
                st.push({x+dx[i],y+dy[i]});
            }
        }
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==1) {
                mxx=INT_MIN;
                mxy=INT_MIN;
                mnx=INT_MAX;
                mny=INT_MAX;
                dfs(i,j);
                int cnt=0;
                for (int p=mnx;p<=mxx;p++) {
                    for (int q=mny;q<=mxy;q++) {
                        if (a[p][q]==0) {
                            cnt++;
                            break;
                        }
                    }
                }
                if (cnt==0) {
                    res++;
                }
            }
        }
    }
    cout<<res;
}
