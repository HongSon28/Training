#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
vector<int>L[N+5],pos[N+5];
int f[N+5],g[N+5];
int inf=1e9;
int main() {
    freopen("TEAMS.INP","r",stdin);
    freopen("TEAMS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    sort(a+1,a+1+n,greater<int>());
    for (int i=1;i<=n;i++)
        if (i+a[i]-1<=n)
            L[i+a[i]-1].push_back(i);
    for (int i=1;i<a[1];i++) f[i]=-inf;
    f[a[1]]=1;
    g[a[1]]=a[1];
    for (int j=a[1]+1;j<=n;j++) {
        f[j]=f[j-1];
        for (auto i:L[j])
            f[j]=max(f[j],f[i-1]+1);
    }
    for (int j=a[1]+1;j<=n;j++) {
        if (f[j]>f[j-1]) {
            g[j]=inf;
            for (auto i:L[j])
                if (f[j]==f[i-1]+1)
                    g[j]=min(g[j],max(g[i-1],j-i+1));
        } else {
            if ((long long)g[j-1]*f[j-1]==j-1)
                g[j]=g[j-1]+1;
            else
                g[j]=g[j-1];
            for (auto i:L[j])
                if (f[j]==f[i-1]+1)
                    g[j]=min(g[j],max(g[i-1],j-i+1));
        }
    }
    cout<<f[n]<<'\n';
    int j=n;
    int last=f[n];
    for (int i=n;i>=1;i--) {
        if (f[i-1]==last-1&&g[i-1]<=g[n]&&a[i]<=j-i+1) {
            cout<<j-i+1<<' ';
            for (int t=i;t<=j;t++) {
                cout<<pos[a[t]].back()<<' ';
                pos[a[t]].pop_back();
            }
            cout<<'\n';
            last--;
            j=i-1;
        }
    }
}
