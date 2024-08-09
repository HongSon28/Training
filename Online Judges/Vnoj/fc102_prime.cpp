#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+5];
int n,a,b;
long long sum[N+5],cnt[N+5];
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i*i<=N;i++) {
        if (p[i]) for (int j=i*i;j<=N;j+=i) p[j]=false;
    }
    for (int i=1;i<=N;i++) {
        sum[i]=sum[i-1];
        cnt[i]=cnt[i-1];
        if (p[i]) {
            cnt[i]++;
            sum[i]+=i;
        }
    }
}
int main() {
    seive();
    cin>>n;
    while (n--) {
        cin>>a>>b;
        cout.precision(2);
        cout<<fixed<<double(sum[b]-sum[a-1])/double(cnt[b]-cnt[a-1])<<endl;
    }
}
