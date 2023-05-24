#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int tv[N+5];
int a[N+5];
int mx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SUBSETSUM.INP","r",stdin);
    freopen("SUBSETSUM.OUT","w",stdout);
    int n,s;
    cin>>n>>s;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mx+=a[i];
    }
    if (mx<s) {
        cout<<"NO";
        return 0;
    }
    int dp[s+1]={};
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=s;j>=a[i];j--) {
            if (dp[j]==0&&dp[j-a[i]]==1) {
                dp[j]=1;
                tv[j]=i;
            }
        }
    }
    if (dp[s]==1) {
        cout<<"YES"<<endl;
        set<int>kq;
        kq.insert(tv[s]);
        int temp=s-a[tv[s]];
        while (true) {
            if (temp==0) break;
            kq.insert(tv[temp]);
            temp-=a[tv[temp]];
        }
        for (auto i:kq) cout<<i<<' ';
    } else {
        cout<<"NO";
    }
}

