#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int x[N+5];
bool check(int w) {
    int cnt=0;
    for (int i=0;i<n-1;i++) {
        cnt+=(x[i+1]-x[i]+1)/w;
    }
    if (cnt>k) return true;
    return false;
}
int main() {
    freopen("FENCE.INP","r",stdin);
    freopen("FENCE.OUT","w",stdout);
    cin>>n>>k;
    int mn=INT_MAX;
    cin>>x[0];
    for (int i=1;i<n;i++) {
        cin>>x[i];
        mn=min(mn,x[i]-x[i-1]);
    }
    sort(x,x+n);
    int lo=1,hi=mn;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) {
            lo=mid;
        } else {
            hi=mid-1;
        }
        //cout<<lo<<' '<<hi<<' '<<mid<<endl;
    }
    cout<<lo;
}
