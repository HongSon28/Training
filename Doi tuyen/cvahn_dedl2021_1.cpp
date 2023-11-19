#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int a[N+5][N+5];
int row[N+5],col[N+5],res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (row[i]==col[j]) res++;
        }
    }
    cout<<res;
}
