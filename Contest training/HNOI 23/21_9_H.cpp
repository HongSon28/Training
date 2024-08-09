#include<bits/stdc++.h>
using namespace std;
const int N=5000,MX=sqrt(N);
int prime[N+5],v1[N+5];
int idx,idx2;
vector<vector<int>>v2(N+5);
bool p[MX+5];
bool used[(1<<19)+5];
int dp[(1<<19)+5];
int temp[(1<<19)+5];
int n,res;
int a;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i<=MX;i++) {
        if (p[i]) {
            prime[idx]=i;
            idx++;
            for (int j=i*i;j<=MX;j+=i) p[j]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a;
        int bit=0;
        for (int j=0;j<idx;j++) {
            if (a%prime[j]!=0) continue;
            while (a%prime[j]==0) a/=prime[j];
            bit|=(1<<j);
        }
        if (a==1&&!used[bit]) {
            v1[idx2]=bit;
            idx2++;
            used[bit]=true;
        }
        else if (a!=1) v2[a].push_back(bit);
    }
    for (int i=0;i<idx2;i++) {
        for (int bit=0;bit<(1<<19);bit++) {
            if ((bit&v1[i])==0) dp[bit|v1[i]]=max(dp[bit|v1[i]],dp[bit]+1);
        }
    }
    for (auto i:v2) {
        if (i.empty()) continue;
        memset(used,false,sizeof(used));
        for (int j=0;j<(1<<19);j++) temp[j]=dp[j];
        for (auto j:i) {
            if (used[j]) continue;
            used[j]=true;
            for (int bit=0;bit<(1<<19);bit++) {
                if ((bit&j)==0) temp[bit|j]=max(temp[bit|j],dp[bit]+1);
            }
        }
        for (int j=0;j<(1<<19);j++) dp[j]=temp[j];
    }
    for (int i=0;i<(1<<19);i++) res=max(res,dp[i]);
    cout<<res;
}
