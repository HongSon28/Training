#include<bits/stdc++.h>
using namespace std;
long long L,R,res;
long long mn=1e18;
long long sum (long long start, long long ed) {
    return (ed+start)*(ed-start+1)/2;
}
int main() {
    freopen("TIMGIUA.INP","r",stdin);
    freopen("TIMGIUA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>L>>R;
    long long lo=L,hi=R-1;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        long long x=sum(L,mid)-sum(mid+1,R);
        //cout<<lo<<' '<<hi<<' '<<mid<<' '<<x<<endl;
        if (abs(x)<mn) {
            mn=abs(x);
            res=mid;
        }
        if (x>0) {
            hi=mid-1;
        } else if (x<0) {
            lo=mid+1;
        } else {
            break;
        }
    }
    cout<<res;
}
