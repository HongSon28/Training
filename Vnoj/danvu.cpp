#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5],b[N+5];
int res;
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int i=1,j=1;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    while (i<=n&&j<=m) {
        if (a[i]>b[j]) {
            res++;
            i++;
            j++;
        } else i++;
    }
    cout<<res;
}
