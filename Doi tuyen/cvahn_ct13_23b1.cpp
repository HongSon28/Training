#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool p[N+5];
vector<long long>prime;
long long res;
long long n,t;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (long long j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("TICHBASO.INP","r",stdin);
    freopen("TICHBASO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0;i<prime.size()-2;i++) {
            if (prime[i]*prime[i+1]*prime[i+2]<=n) res=prime[i]*prime[i+1]*prime[i+2];
            else break;
        }
        cout<<res<<'\n';
    }
}
