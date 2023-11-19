#include<bits/stdc++.h>
using namespace std;
const int N=1000,maxN=1e6;
int n,res;
long long a[N+5];
set<long long>s,temp;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    s.insert(a[1]);
    for (int i=2;i<=n;i++) {
        for (auto u:s) {
            long long v=__gcd(u,a[i]);
            if (a[i]/v>1) temp.insert(a[i]/v);
            if (v>1) temp.insert(v);
            if (u/v>1) temp.insert(u/v);
        }
        swap(s,temp);
        temp.clear();
    }
    for (auto k:s) {
        int cnt=0;
        for (int i=1;i<=n;i++) {
            if (a[i]%k==0) cnt++;
        }
        res=max(res,cnt);
    }
    cout<<res;
}
