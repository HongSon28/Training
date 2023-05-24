#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n+1],p[n+1],mn[n+1];
    mn[0]=INT_MAX;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        mn[i]=min(mn[i-1],p[i]);
    }
    long long res=0;
    for (int i=1;i<=n;i++) {
        res+=a[i]*mn[i];
    }
    cout<<res;
}
