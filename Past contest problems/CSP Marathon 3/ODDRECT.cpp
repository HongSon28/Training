#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int c[N+5][N+5];
int n;
int res;
int a[N+5][N+5];
int main() {
    freopen("ODDRECT.INP","r",stdin);
    freopen("ODDRECT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x_1,y_1,x_2,y_2;
        cin>>x_1>>y_1>>x_2>>y_2;
        for (int j=x_1;j<=x_2;j++) {
            c[j][y_1]++;
            c[j][y_2+1]--;
        }
    }
    for (int i=0;i<=N;i++) {
        for (int j=0;j<=N;j++) {
            a[i][j]=a[i][j-1]+c[i][j];
            if (a[i][j]%2==1) res++;
        }
    }
    cout<<res;
}
