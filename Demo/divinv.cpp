#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
#define ll long long
ll n,k,cnt;
ll a[N+5];
vector<int>cprs;
vector<ll>cur(N+5),dp(N+5);
ll t[N+5],tt[N+5];
void update(int x) {
    for (;x>0;x-=x&-x) tt[x]++;
}
ll gett(int x) {
    ll ans=0;
    for (;x<=n;x+=x&-x) ans+=tt[x];
    return ans;
}
void update1(int x) {
    for (;x<=n;x+=x&-x) t[x]++;
}
void update2(int x) {
    for (;x<=n;x+=x&-x) t[x]--;
}
ll get(int x) {
    ll ans=0;
    for (;x>0;x-=x&-x) ans+=t[x];
    return ans;
}
void calc(int l,int r,int opt1,int opt2) {
    if (l>r) return;
    int mid=(l+r)/2;
    pair<ll,int>ans={LLONG_MAX,-1};
    ll val=0;
    cout<<l<<' '<<r<<' '<<opt1<<' '<<opt2<<endl;
    cnt++;
    for (int k=mid;k>opt2;k--) {
        update1(a[k]);
        val+=get(a[k]-1);
    }
    for (int k=min(opt2,mid);k>=opt1;k--) {
        update1(a[k]);
        val+=get(a[k]-1);
        //cout<<k<<' '<<mid<<' '<<dp[k-1]<<' '<<val<<' '<<k<<endl;
        if (dp[k-1]+val<ans.first) ans={dp[k-1]+val,k};
    }
    for (int k=min(opt2,mid);k>=opt1;k--) update2(a[k]);
    for (int k=mid;k>opt2;k--) update2(a[k]);
    cur[mid]=ans.first;
    int opt=ans.second;
    //cout<<ans.first<<' '<<opt<<endl<<endl;
    calc(l,mid-1,opt1,opt);
    calc(mid+1,r,opt,opt2);
}
int main(){
    freopen("divinv.inp","r",stdin);
    freopen("divinv.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    //cout<<endl;
    for (int i=1;i<=n;i++) {
        update(a[i]);
        dp[i]=dp[i-1]+gett(a[i]+1);
    }
    for (int i=0;i<=n;i++) t[i]=0;
    //for (int i=1;i<=n;i++) cout<<dp[i]<<' ';
    //cout<<endl<<endl;
    for (int i=2;i<=k;i++) {
        calc(i,n,i,n);
        dp=cur;
        //for (int j=1;j<=n;j++) cout<<dp[j]<<' ';
        //cout<<endl<<endl;
    }
    cout<<dp[n]<<' '<<cnt;
}

