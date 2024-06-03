#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int res,s0[N+5],s1[N+5],sum[N+5],c[2*N+5];
string s;
signed main(){
    cin>>s;
    int n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            s1[i]=s1[i-1];
            s0[i]=s0[i-1]+1;
        }else{
            s0[i]=s0[i-1];
            s1[i]=s1[i-1]+1;
        }
        sum[i]=s1[i]-s0[i];
    }
    for(int i=0;i<=n;i++) c[sum[i]+N]++;
    for(int i=0;i<=N*2;i++) res+=c[i]*(c[i]-1)/2;
    cout<<res;
}