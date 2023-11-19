#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,m;
int a[N+5],b[N+5],mn[N+5],mx[N+5];
bool c[N+5];
void seive() {
    for (int i=1;i<=n;i++) {
        if (a[i]==a[i-1]) continue;
        for (int j=a[i];j<=N;j+=a[i]) {
            c[j]=true;
            mx[j-1]=a[i]-1;
        }
    }
    for (int i=1;i<=n;i++) mx[N+1]=max(mx[N+1],(N+1)%a[i]);
    for (int i=1;i<=N;i++) {
        if (c[i]) mn[i]=0;
        else mn[i]=mn[i-1]+1;
    }
    for (int i=N;i>=1;i--) {
        mx[i]=max(mx[i+1]-1,mx[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=m;i++) cin>>b[i];
    seive();
    for (int i=1;i<=m;i++)
        cout<<mn[b[i]]<<' '<<mx[b[i]]<<'\n';
}
