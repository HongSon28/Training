#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n1,n2,k;
long long c[N+5];
int res;
void calc(){
    for (long long i=1;i<=N;i++) {
        for (long long j=i*2;j<=N;j+=i) c[j]+=i;
    }
}
int main() {
    calc();
    cin>>n1>>n2>>k;
    for (int i=n1;i<=n2;i++) {
        if (c[i]+k==i&&i!=1) {
            res++;
        }
    }
    cout<<res;
}
