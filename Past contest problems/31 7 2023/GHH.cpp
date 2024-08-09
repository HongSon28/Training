#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long t;
long long c[N+5];
void seive() {
    for (long long i=1;i<=N;i++) {
        for (long long j=i;j<=N;j+=i) c[j]+=i;
    }
}
int main() {
    seive();
    cin>>n;
    while (n--) {
        cin>>t;
        if (2*t<=c[t]) cout<<'1'<<'\n';
        else cout<<'0'<<'\n';
    }
}
