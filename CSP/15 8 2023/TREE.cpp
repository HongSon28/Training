#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int d[N+5];
int par[N+5];
int i,mx;
void dfs(int u) {
    mx=max(mx,u);
    if (i>n) {
        cout<<"NIE";
        exit(0);
    }
    if (d[u]==a[i]) {
        cout<<u<<endl;
        i++;
    }
    else if (d[u]>a[i]) {
        cout<<"NIE";
        exit(0);
    } else {
        d[u+1]=d[u]+1;
        par[u+1]=u;
        dfs(u+1);
        d[u+2]=d[u]+1;
        par[u+2]=u;
        dfs(u+2);
    }
}
int main() {
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    int u=1;
    i=1;
    dfs(1);
    for (int i=1;i<=10;i++) cout<<par[i];
}
