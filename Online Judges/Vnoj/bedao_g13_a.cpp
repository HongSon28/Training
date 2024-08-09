#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long c[N+5];
long long n,res;
void seive() {
    for (int i=1;i<=N;i++){
        for (int j=i;j<=N;j+=i) c[j]++;
    }
}
int main() {
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
        res+=c[i]*c[n-i];
    }
    cout<<res;
}
