#include<bits/stdc++.h>
using namespace std;
int a[103][103],res=0;
bool v[103][103];
void dequy(int i, int j) {
    if (a[i][j]==1&&v[i][j]==false) {
        v[i][j]=true;
        dequy(i+1,j);
        dequy(i,j+1);
        dequy(i-1,j);
        dequy(i,j-1);
    }
}
int main() {
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    memset(v,false,sizeof(v));
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==1&&v[i][j]==false)
                res++;
            dequy(i,j);
        }
    }
    cout<<res;
}
