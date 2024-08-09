#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
long long c[N+5];
void seive() {
    for (long long i=1;i<=N;i++) {
        for (long long j=i;j<=N;j+=i) c[j]+=i;
    }
}
vector<int>v;
int main() {
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (2*a[i]<=c[a[i]]) v.push_back(a[i]);
    }
    cout<<v.size()<<'\n';
    for (auto i:v) cout<<i<<'\n';
}

