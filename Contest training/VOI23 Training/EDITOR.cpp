#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,dp[N+5],z[N+5];
string s;
int main(){
    freopen("EDITOR.INP","r",stdin);
    freopen("EDITOR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>s;
        n=s.size();
        int l=0,r=0;
        z[0]=0;
        for (int i=1;i<n;i++) {
            z[i]=0;
            if (i<r) z[i]=min(r-i,z[i-l]);
            while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
            if (i+z[i]>r) {
                l=i;
                r=i+z[i];
            }
        }
        dp[0]=1;
        r=1;
        for (int i=1;i<n;i++) {
            int q=min(z[i],i);
            for (int j=r;j<i+q;j++) dp[j]=dp[i-1]+1;
            r=max(r,i+q);
            if (i==r){
                dp[i]=dp[i-1]+1;
                r=i+1;
            }
        }
        cout<<dp[n-1]<<'\n';
    }
}
