#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool dp[N+5];
int n;
int a[N+5],b[N+5],c[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        c[i]=abs(a[i]-b[i]);
    }

}
