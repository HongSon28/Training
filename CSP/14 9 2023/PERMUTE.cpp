#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int p[N+5];
int n;
bool vis[N+5];
int d[N+5];
int mx[N+5];
long long mod=123456789;
long long res=1;
void seive() {
    iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("PERMUTE.INP","r",stdin);
    freopen("PERMUTE.OUT","w",stdout);
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            int cnt=1;
            int j=i;
            while (p[j]!=i) {
                j=p[j];
                cnt++;
                vis[j]=true;
            }
            while (cnt!=1) {
                int div=d[cnt];
                int cc=0;
                while (cnt%div==0) {
                    cnt/=div;
                    cc++;
                }
                mx[div]=max(mx[div],cc);
            }
        }
    }
    for (long long i=1;i<=N;i++) {
        for (int j=0;j<mx[i];j++) {
            res*=i;
            res%=mod;
        }
    }
    cout<<res;
}
