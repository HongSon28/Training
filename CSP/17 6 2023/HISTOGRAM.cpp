#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int res;
int h[N+5];
int main() {
    freopen("HISTOGRAM.INP","r",stdin);
    freopen("HISTOGRAM.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) {
        int target=h[i];
        int sum=0;
        for (int j=1;j<=n;j++) {
            if (h[j]>=target)
                sum+=target;
            else
                sum=0;
            res=max(res,sum);
        }
    }
    cout<<res;
}
