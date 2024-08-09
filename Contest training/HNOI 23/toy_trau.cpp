#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
pair<long long,long long>p[N+5];
long long pre_mx[N+5],pre_mn[N+5],suf_mx[N+5],suf_mn[N+5];
long long res=LLONG_MAX;
int main() {
    //freopen("toy.inp","r",stdin);
    //freopen("toy.ans","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    pre_mn[0]=suf_mn[n+1]=INT_MAX;
    for (int i=1;i<=n;i++) {
        pre_mx[i]=max(pre_mx[i-1],p[i].second);
        pre_mn[i]=min(pre_mn[i-1],p[i].second);
    }
    for (int i=n;i>=1;i--) {
        suf_mx[i]=max(suf_mx[i+1],p[i].second);
        suf_mn[i]=min(suf_mn[i+1],p[i].second);
    }
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (i==1&&j==n) continue;
            long long s1=p[j].first-p[i].first;
            long long s2=max(pre_mx[i-1],suf_mx[j+1]);
            long long s3=min(pre_mn[i-1],suf_mn[j+1]);
            //cout<<i<<' '<<j<<' '<<s1<<' '<<s2<<' '<<s3<<endl;
            res=min(res,s1+s2-s3);
        }
    }
    cout<<res;
}

