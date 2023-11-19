#include<bits/stdc++.h>
using namespace std;
struct k{
    int a,b,c,index;
};
bool comp (k a, k b) {
    if (a.b==b.b) return a.a<b.a;
    return a.b<b.b;
}
k a[1001];
int n,res,t;
int dp[1001];
k last;
vector<int>v;
int main() {
    freopen("thuemay.inp","r",stdin);
    freopen("thuemay.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].index=i;
    }
    sort(a+1,a+1+n,comp);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            if (a[j].b<a[i].a) {
                dp[i]=max(dp[i],dp[j]+a[i].c);
            }
        }
        if (res<dp[i]) {
            res=dp[i];
            last=a[i];
            t=i;
        }
    }
    v.push_back(last.index);
    int cnt=1;
    int temp=res-last.c;
    while (true) {
        if (dp[t]==temp&&last.a>=a[t].b) {
            v.push_back(a[t].index);
            last=a[t];
            temp-=last.c;
            cnt++;
        }
        if (temp==0) break;
        t--;
    }
    cout<<cnt<<' '<<res<<endl;
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++) cout<<v[i]<<'\n';
}
