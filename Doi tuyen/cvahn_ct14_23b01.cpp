#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+5];
long long n,res;
vector<long long>prime;
void seive() {
    memset(p,true,sizeof(p));
    for (long long i=2;i*i<=N/2;i++) {
        if (p[i])
            for (long long j=i*i;j<=N/2;j+=i) p[j]=false;
    }
    for (int i=2;i<=N/2;i++)
        if (p[i])
            prime.push_back(i);
}
int main() {
    freopen("NUANT.INP","r",stdin);
    freopen("NUANT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n;
    for (int i=0;i<prime.size();i++) {
        for (int j=i+1;j<prime.size();j++) {
            if (prime[i]*prime[j]<=n) res++;
            else break;
        }
    }
    for (auto i:prime) {
        if (i*i*i<=n) res++;
        else break;
    }
    cout<<res;
}
