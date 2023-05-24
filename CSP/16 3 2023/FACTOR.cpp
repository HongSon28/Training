#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
bool p[N+1];
vector<long long>v;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2; i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("FACTOR.INP","r",stdin);
    freopen("FACTOR.OUT","w",stdout);
    sang();
    long long n;
    cin>>n;
    for (int i=0;i<v.size();i++) {
        while (n%v[i]==0) {
            cout<<v[i]<<' ';
            n/=v[i];
        }
    }
    if (n!=1) cout<<n;
}
