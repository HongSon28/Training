#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=100;
int m,n;
int t[N+5][M+5];
int c[N+5];
int virus[M+5];
vector<int>v1,v2,v3;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++){
            cin>>t[i][j];
            if (t[i][j]==1) c[i]++;
        }
        cin>>t[i][m+1];
    }
    for (int i=1;i<=n;i++) {
        if (t[i][m+1]==0) {
            for (int j=1;j<=m;j++)
                if (t[i][j]==1&&virus[j]==0) {
                    virus[j]=1;
                    for (int k=1;k<=n;k++) {
                        if (t[k][j]==1) {
                            t[k][j]=0;
                            c[k]--;
                        }
                    }
                }
        }
    }
    while (true) {
        bool flag=false;
        for (int i=1;i<=n;i++) {
            if (c[i]==1&&t[i][m+2]==0) {
                for (int j=1;j<=m;j++) {
                    if (t[i][j]) {
                        virus[j]=2;
                        for (int k=1;k<=n;k++) {
                            if (t[k][j]==1) {
                                t[k][m+2]=1;
                                t[k][j]=0;
                                c[k]--;
                            }
                        }
                    }
                }
                flag=true;
            }
        }
        if (!flag) break;
    }
    for (int i=1;i<=m;i++) {
        if (virus[i]==1) v1.push_back(i);
        else if (virus[i]==2) v2.push_back(i);
        else v3.push_back(i);
    }
    cout<<v1.size()<<' ';
    for (auto i:v1) cout<<i<<' ';
    cout<<'\n';
    cout<<v2.size()<<' ';
    for (auto i:v2) cout<<i<<' ';
    cout<<'\n';
    cout<<v3.size()<<' ';
    for (auto i:v3) cout<<i<<' ';
}
/*
3 3
1 0 0 0
1 1 1 1
0 1 0 0
*/
