#include<bits/stdc++.h>
using namespace std;
int n,sum,res;
const int N=2e6;
int a[21];
bool dp[N+5];
bool flag=false;
bool prime[N+5];
void seive() {
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for (int i=2;i<=N;i++) {
        if (prime[i]==true) {
            for (int j=i*2;j<=N;j+=i) prime[j]=false;
        }
    }
}
int main() {
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for (int i=1;i<=n;i++) {
        for (int s=N;s>=i;s--) {
            if (dp[s-a[i]]) dp[s]=true;
        }
    }
    for (int i=0;i<=N;i++){
        if (dp[i]==true) {
            int j=sum-i;
            int dif=abs(i-j);
            if (prime[dif]) {
                res=max(res,dif);
                flag=true;
            }
        }
    }
    if (flag)
        cout<<res;
    else
        cout<<-1;
}
