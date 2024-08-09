#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    int t=a[k];
    int res=0;
    for (int i=1;i<=n;i++) {
        if (a[i]>=t&&a[i]>0) res++;
    }
    cout<<res;
}
