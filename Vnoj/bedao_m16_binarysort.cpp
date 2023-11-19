#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long res;
long long a[N+5],c[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[i]=c[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        if (a[i]==0) res+=c[i];
    }
    cout<<res;
}
