#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
int pre[N+5],suf[N+5];
vector<int>v;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        pre[i]=__gcd(pre[i-1],a[i]);
        if (pre[i]!=pre[i-1]) v.push_back(i);
    }
    for (int i=n;i>=1;i--) suf[i]=__gcd(suf[i+1],a[i]);
    for (auto i:v) {
        for (int j=1;j<=n;j++) {
            if (i==j) continue;
            cout<<i<<' '<<j<<endl;
        }
    }
}
