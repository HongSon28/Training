#include<bits/stdc++.h>
using namespace std;
const int N=2000;
struct Segment{
    int l,r,val;
};
int n,m,res;
int a[N+5][N+5];
vector<vector<Segment>>v(N+5);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("kimtuthap.inp","r",stdin);
    freopen("kimtuthap.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    int l=1,r=1,cur=a[n][1];
    while (r<=m) {
        if (a[n][r]==0) {
            if (cur!=0) {
                v[n].push_back({l,r-1,cur});
                res=max(res,cur);
            }
            r++;
            l=r;;
            cur=a[n][r];
        } else {
            r++;
            cur+=a[n][r];
        }
    }
    if (cur!=0) {
        v[n].push_back({l,r-1,cur});
        res=max(res,cur);
    }
    for (int i=n-1;i>=1;i--) {
        for (auto Seg:v[i+1]) {
            //cout<<i+1<<' '<<Seg.l<<' '<<Seg.r<<' '<<Seg.val<<endl;
            l=Seg.l,r=l,cur=a[i][l];
            while (r<=Seg.r) {
                if (a[i][r]==0) {
                    if (cur!=0) {
                        v[i].push_back({l,r-1,Seg.val+cur});
                        res=max(res,Seg.val+cur);
                    }
                    r++;
                    l=r;
                    cur=a[i][r];
                } else {
                    r++;
                    cur+=a[i][r];
                }
            }
            if (cur-a[i][r]!=0) {
                v[i].push_back({l,r-1,Seg.val+cur-a[i][r]});
                res=max(res,Seg.val+cur-a[i][r]);
            }
        }
        l=1,r=1,cur=a[i][1];
        while (r<=m) {
            if (a[i][r]==0) {
                if (cur!=0) {
                    v[i].push_back({l,r-1,cur});
                    res=max(res,cur);
                }
                r++;
                l=r;;
                cur=a[i][r];
            } else {
                r++;
                cur+=a[i][r];
            }
        }
        if (cur!=0) {
            v[i].push_back({l,r-1,cur});
            res=max(res,cur);
        }
    }
    cout<<res;
}
