#include<bits/stdc++.h>
using namespace std;
long long n;
const int N=1e6;
long long cnt;
bool p[N+5];
long long sum[N+5];
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i<=N;i++) {
        if (p[i]) {
            for (long long j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("PRIME.INP","r",stdin);
    freopen("PRIME.OUT","w",stdout);
    seive();
    cin>>n;
    for (int i=1;i<=N;i++) {
        sum[i]=sum[i-1];
        if (p[i]) sum[i]++;
    }
    //cout<<prime.size();
    for (long long a=1;a*a*a*a*a<=n;a++) {
        if (p[a]) {
            for (long long c=a+1;a*a*a*c*c<=n;c++) {
                if (p[c]) {
                    long long l=a+1;
                    long long r=min(c-1,n/a/a/c/c);
                    if (l<=r)
                        cnt+=sum[r]-sum[l-1];
                }
            }
        }
    }
    cout<<cnt;
}
