#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1],f[n+1],g[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    deque<int> mi,ma;
    f[0]=1,g[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=f[i-1];j<=i;j++) {
            while (!mi.empty() && mi.front() < j) mi.pop_front();
            while (!ma.empty() && ma.front() < j) ma.pop_front();
            while (!mi.empty() && a[mi.back()] > a[i]) mi.pop_back();
            while (!ma.empty() && a[ma.back()] < a[i]) ma.pop_back();
            mi.push_back(i);
            ma.push_back(i);
            if (a[ma.front()] - a[mi.front()] <= k) {
                f[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) g[i]=max(i-f[i]+1,g[i-1]);
    int ans=0;
    for (int i=1;i<=n;i++)
        ans = max(ans,i-f[i]+1+g[f[i]-1]);
    cout<<ans;
}
