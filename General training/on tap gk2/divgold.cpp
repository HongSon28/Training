#include<bits/stdc++.h>
using namespace std;
int n,sum,res=INT_MAX;
int a,b;
int v[30];
bool dp[50001];
long long f[50001];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        sum+=v[i];
    }
    dp[0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=sum;j>=v[i];j--) {
            if (dp[j]==false && dp[j-v[i]]==true) dp[j]=true;
        }
    }
    for(int i=0;i<=sum;i++) {
        if (dp[i]==true) {
            int j=sum-i;
            if (res>abs(i-j)) {
                res=abs(i-j);
            }
        }
    }
    cout<<res<<endl;
    int s=(sum-res)/2;
    f[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=s;j>=v[i];j--) {
            f[j]+=f[j-v[i]];
        }
    }
    cout<<f[s];
}
