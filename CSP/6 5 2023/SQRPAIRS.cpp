#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n;
int cnt[N+5];
int d[N+5];
void sang() {
    iota(d,d+N+5,0);
    for (int i=2; i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int mask(int x) {
    int res=1;
    while (x>1) {
        int div=d[x];
        int t=0;
        for (;x%div==0;x/=div)t++;
        if (t%2==1) res*=div;
    }
    return res;
}
int main() {
    freopen("SQRPAIRS.INP","r",stdin);
    freopen("SQRPAIRS.OUT","w",stdout);
    sang();
    cin>>n;
    int res=0;
    for (int i=1;i<=n;i++) {
        int t=mask(i);
        res+=cnt[t];
        cnt[t]++;
    }
    cout<<res;
}
