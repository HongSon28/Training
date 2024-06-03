#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,t;
char a[N+5][N+5];
int cont(int x,int y) {
    int ans=0;
    for (int i=1;i<=n;i++)
        if (a[x][i]=='X'&&a[y][i]=='X') ans++;
    return ans;
}
void solve() {
    int row=-1,col=-1;
    for (int i=1;i<=n;i++) {
        int cnt=0;
        for (int j=1;j<=n;j++) cnt+=(a[i][j]=='X');
        if (cnt==1&&row!=-1) {
            cout<<"IMPOSSIBLE"<<'\n';
            return;
        } else if (cnt==1&&row==-1) {
            row=i;
            for (int j=1;j<=n;j++)
                if (a[i][j]=='X') col=j;
        }
        if (cnt>2) {
            cout<<"IMPOSSIBLE"<<'\n';
            return;
        }
    }
    if (row==-1) {
        cout<<"IMPOSSIBLE"<<'\n';
        return;
    }
    for (int i=1;i<=n;i++) {
        if ((i!=row&&a[i][col]=='X')||(i!=col&&a[row][i]=='X')) {
            cout<<"IMPOSSIBLE"<<'\n';
            return;
        }
    }
    for (int i=1;i<=n;i++) {
        if (i!=row) {
            int cnt=0;
            for (int j=1;j<=n;j++) {
                if (i==j) continue;
                int temp=cont(i,j);
                if (temp==0) continue;
                if (temp==1) {
                    cout<<"IMPOSSIBLE"<<'\n';
                    return;
                }
                cnt++;
            }
            if (cnt!=1) {
                cout<<"IMPOSSIBLE"<<'\n';
                return;
            }
        }
    }
    cout<<"POSSIBLE"<<'\n';
}
int main() {
    freopen("square.inp","r",stdin);
    freopen("square.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>a[i][j];
        solve();
    }
}
