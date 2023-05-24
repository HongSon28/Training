#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
vector<long long>prime;
void seive() {
    bool p[N+5];
    fill(p,p+N+5,true);
    for (long long i=2;i<=N;i++) {
        if (p[i]==true) {
            for (long long j=i*2;j<=N;j+=i) p[j]=false;
            prime.push_back(i);
        }
    }
}
int main() {
    seive();
    map<long long, long long>mp;
    long long m,n,res=1;
    cin>>m>>n;
    for (int i=0;i<prime.size();i++) {
        if(m==1) break;
        while (m%prime[i]==0) {
            m/=prime[i];
            mp[prime[i]]++;
        }
    }
    if (m!=1) mp[m]++;
    for (int i=0;i<prime.size();i++) {
        if(n==1) break;
        while (n%prime[i]==0) {
            n/=prime[i];
            mp[prime[i]]++;
        }
    }
    if (n!=1) mp[n]++;
    for (auto i=mp.begin();i!=mp.end();i++) {
        res*=(i->second)+1;
    }
    cout<<res;
}
