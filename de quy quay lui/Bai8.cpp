#include<bits/stdc++.h>
using namespace std;
int n;
int a[11][11];
int sum=0;
int res=INT_MIN;
bool c[11];
void dequy(int k) {
    for (int i=1;i<=3;i++) {
        if (c[i]==true) {
            sum+=a[k][i];
            c[i]=false;
            if (k==n) {
                res=max(res,sum);
            }
            else {
                dequy(k+1);
            }
            c[i]=true;
            sum-=a[k][i];
        }
    }
}
int main() {
    memset(c,true,sizeof(c));
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    dequy(1);
    cout<<res;
}
