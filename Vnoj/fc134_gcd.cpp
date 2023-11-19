#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+5],b[N+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int g=a[2]-a[1];
    for (int i=2;i<=n;i++) g=__gcd(g,a[i]-a[1]);
    if (n==1) g=0;
    for (int i=1;i<=m;i++)
        cout<<abs(__gcd(g,a[1]+b[i]))<<' ';
}
