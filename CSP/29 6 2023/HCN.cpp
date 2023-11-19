#include<bits/stdc++.h>
using namespace std;
const int N=300;
const int maxN=1e6;
int m,n;
int a[N+5][N+5];
int p[maxN+5];
int res;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i<=maxN;i++) {
        if (p[i]) for (long long j=i*i;j<=maxN;j+=i) p[j]=false;
    }
}
int main() {
    freopen("HCN.INP","r",stdin);
    freopen("HCN.OUT","w",stdout);
    seive();
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int left=1;left<n;left++) {
        for (int right=left+1;right<=n;right++) {
            int cnt1=0,cnt2=0;
            for (int i=1;i<=m;i++) {
                if (p[a[i][right]]&&p[a[i][left]]) cnt2++;
                else if (p[a[i][left]]) cnt1++;
                else if (p[a[i][right]]) cnt1++;
            }
            res+=cnt1*cnt2+cnt2*(cnt2-1)/2;
        }
    }
    cout<<res;
}
