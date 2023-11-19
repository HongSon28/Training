#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MKPALIND.INP","r",stdin);
    freopen("MKPALIND.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int lo=1,hi=n;
    long long suml=a[1],sumr=a[n];
    while (lo<hi) {
        if (suml==sumr) {
            lo++;
            hi--;
            suml+=a[lo];
            sumr+=a[hi];
        } else if (suml<sumr) {
            lo++;
            suml+=a[lo];
            res++;
        } else {
            hi--;
            sumr+=a[hi];
            res++;
        }
    }
    cout<<res;
}
