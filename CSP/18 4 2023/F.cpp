#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,res;
int b[N+5];
multiset<int>a;
int main() {
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    cin>>n;
    int t;
    for (int i=0;i<n;i++) {
        cin>>t;
        a.insert(t);
    }
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(b,b+n);
    for (auto i=1;i<=n;i++) {
        auto it=a.lower_bound(b[i]);
        if (it==a.begin())
        {
            it=a.end();
            it--;
            a.erase(it);
        }
        else {
            it--;
            res++;
            a.erase(it);
        }
    }
    cout<<res;
}
