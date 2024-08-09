#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k,t;
int a[N+5];
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=k;
    }
    while (k--) {
        cin>>t;
        a[t]--;
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
}
