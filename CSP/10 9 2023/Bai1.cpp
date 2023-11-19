#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        long long lo=0,hi=1e6,res=0;
        while (lo<=hi) {
            long long mid=(lo+hi)/2;
            if (mid*(mid+1)*(mid+2)<=n) {
                res=mid*(mid+1)*(mid+2);
                lo=mid+1;
            } else hi=mid-1;
        }
        cout<<res<<'\n';
    }
}
