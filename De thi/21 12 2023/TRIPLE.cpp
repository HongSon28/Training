#include<bits/stdc++.h>
using namespace std;
const int N=3e5,M=3e3;
int n;
long long x[N+5],y[N+5],mn[N+5],cnt[N+5];
long long dist(int i,int j) {
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
bitset<M+5>s[M+5],temp;
void solve1() {
    long long res=0;
    for (int i=1;i<=n;i++) {
        mn[i]=1e18;
        for (int j=1;j<=n;j++) {
            if (i!=j) mn[i]=min(mn[i],dist(i,j));
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            for (int k=j+1;k<=n;k++) {
                res+=(mn[i]==mn[j]&&mn[j]==mn[k]&&dist(i,j)==mn[i]&&dist(i,j)==dist(i,k)&&dist(i,k)==dist(j,k));
            }
        }
    }
    cout<<res;
}
void solve2() {
    long long res=0;
    for (int i=1;i<=n;i++) {
        mn[i]=1e18;
        for (int j=1;j<=n;j++) {
            if (i!=j) mn[i]=min(mn[i],dist(i,j));
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i!=j&&mn[i]==mn[j]&&dist(i,j)==mn[i]) {
                s[i].set(j);
                s[j].set(i);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (mn[i]==mn[j]&&dist(i,j)==mn[i]) {
                temp=(s[i]&s[j]);
                res+=temp.count();
            }
        }
    }
    cout<<res/3;
}
int main() {
    freopen("TRIPLE.INP","r",stdin);
    freopen("TRIPLE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    if (n<=300) solve1();
    else solve2();
}
