#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n;
int a[N+1][N+1];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++) cout<<sqrt(a[i][i])<<' ';
}
