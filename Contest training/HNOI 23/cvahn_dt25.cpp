#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int block[N+N+5][N+N+5];
int vis[N+N+5][N+N+5];
int c,s;
int main() {
    cin>>c>>s;
    while (c--) {
        int x,y;
        cin>>x>>y;
        x+=N;
        y+=N;
        block[x][y]=true;
    }
}
