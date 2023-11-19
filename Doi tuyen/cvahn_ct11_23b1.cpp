#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool p[N+5];
long long a,b,res;
vector<long long>prime;
void seive() {
    memset(p,true,sizeof(p));
    for (long long i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (long long j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("CP.INP","r",stdin);
    freopen("CP.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>a>>b;
    for (auto i:prime) {
        if (i*i>=a&&i*i<=b) res++;
    }
    cout<<res;
}
