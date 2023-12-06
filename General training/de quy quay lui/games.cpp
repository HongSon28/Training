#include<bits/stdc++.h>
using namespace std;
int n;
int res=-1e9;
int sum=0;
int a[11][11];
bool c[11];
void rec(int k) {
    for (int i=1;i<=n;i++) {
        if (!c[i]) {
            c[i]=true;
            sum+=a[k][i];
            if (k==n) res=max(res,sum);
            else rec(k+1);
            sum-=a[k][i];
            c[i]=false;
        }
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    rec(1);
    cout<<res;
}
