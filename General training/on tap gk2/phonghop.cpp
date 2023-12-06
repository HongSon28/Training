#include<bits/stdc++.h>
using namespace std;
int n,res,t;
struct phong {
    int l,r,index;
};
phong last;
bool comp (phong a, phong b) {
    if (a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}
phong a[1001];
int dp[1001];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r;
        a[i].index=i;
    }
    sort(a+1,a+n+1,comp);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            if (a[j].r<=a[i].l) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if (res<dp[i]) {
            res=dp[i];
            t=i;
            last=a[i];
        }
        //cout<<dp[i]<<' ';
    }
    cout<<res<<endl;
    vector<int>v;
    v.push_back(last.index);
    int cnt=1;
    int temp=res;
    while (true) {
        if (dp[t]==temp-1&&last.l>=a[t].r) {
            //cout<<a[t].l<<' '<<a[t].r<<' '<<a[t].index<<endl;
            cnt++;
            last=a[t];
            temp--;
            v.push_back(last.index);
        }
        if (cnt==res) break;
        t--;
    }
    for (int i=v.size()-1;i>=0;i--) {
        cout<<v[i]<<' ';
    }
}
