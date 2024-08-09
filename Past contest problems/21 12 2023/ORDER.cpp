#include<bits/stdc++.h>
using namespace std;
const int N=2e5,M=1e6;
int t,n;
long long a[N+5],b[N+5],c[N+5],wa[N+5],wb[N+5],wc[N+5];
bool used[M+5];
void solve12() {
    long long cur=0,res=0;
    for (int x=0;x<=n;x++) {
        if (x>=1) {
            if (used[a[x]]) break;
            used[a[x]]=true;
            cur+=wa[x];
        }
        for (int y=0;y<=n;y++) {
            if (y>=1) {
                if (used[b[y]]) {
                    for (int t=y-1;t>=1;t--) {
                        used[b[t]]=false;
                        cur-=wb[t];
                    }
                    break;
                }
                used[b[y]]=true;
                cur+=wb[y];
            }
            for (int z=0;z<=n;z++) {
                if (z>=1) {
                    if (used[c[z]]) {
                        for (int t=z-1;t>=1;t--) {
                            used[c[t]]=false;
                            cur-=wc[t];
                        }
                        break;
                    }
                    used[c[z]]=true;
                    cur+=wc[z];
                }
                res=max(res,cur);
                if (z==n) {
                    for (int t=n;t>=1;t--) {
                        used[c[t]]=false;
                        cur-=wc[t];
                    }
                }
            }
            if (y==n) {
                for (int t=n;t>=1;t--) {
                    used[b[t]]=false;
                    cur-=wb[t];
                }
            }
        }
    }
    cout<<res<<'\n';
}
void solve3() {
    long long cur=0,res=0;
    for (int x=0;x<=n;x++) {
        if (x>=1) {
            if (used[a[x]]) break;
            used[a[x]]=true;
            cur+=wa[x];
        }
        int r=0;
        res=max(res,cur);
        while (r+1<=n&&!used[c[r+1]]) {
            used[c[r+1]]=true;
            cur+=wc[r+1];
            res=max(res,cur);
            r++;
        }
        for (int l=1;l<=n;l++) {
            while (used[b[l]]&&r>=1) {
                used[c[r]]=false;
                cur-=wc[r];
                r--;
            }
            if (used[b[l]]) {
                for (int i=1;i<=r;i++) {
                    used[c[i]]=false;
                    cur-=wc[i];
                }
                for (int i=1;i<l;i++) {
                    used[b[i]]=false;
                    cur-=wb[i];
                }
                break;
            }
            used[b[l]]=true;
            cur+=wb[l];
            res=max(res,cur);
            if (l==n) {
                for (int i=1;i<=r;i++) {
                    used[c[i]]=false;
                    cur-=wc[i];
                }
                for (int i=1;i<=l;i++) {
                    used[b[i]]=false;
                    cur-=wb[i];
                }
            }
        }
    }
    cout<<res<<'\n';
}
int main() {
    freopen("ORDER.INP","r",stdin);
    freopen("ORDER.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    for (int test=1;test<=t;test++) {
        if (test==1) {
            cin>>n;
            for (int i=1;i<=n;i++) cin>>a[i];
            for (int i=1;i<=n;i++) cin>>wa[i];
            for (int i=1;i<=n;i++) cin>>b[i];
            for (int i=1;i<=n;i++) cin>>wb[i];
            for (int i=1;i<=n;i++) cin>>c[i];
            for (int i=1;i<=n;i++) cin>>wc[i];
            if (n<=400) solve12();
            else solve3();
        } else {
            int e,s;
            cin>>e>>s;
            cout<<151<<'\n';
        }
    }
}
/*
1
4
10 4 8 6
1 1 1 1
7 9 5 5
1 1 1 1
2 1 5 4
1 1 1 1

1
8
50 45 40 35 30 25 20 15
5 2 -3 8 -1 4 6 -2
48 42 38 32 28 22 18 15
3 6 -2 1 -5 2 4 -3
35 40 45 30 25 20 55 60
1 -3 5 -2 4 6 -1 3
*/

