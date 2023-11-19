#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long w[N+5],d[N+5],res;
long long calc(long long m) {
    long long dist=0,cur=0,cnt=0,sum=0;
    for (int i=n;i>=1;i--) {
        dist+=d[i];
        if (cur+dist*w[i]>m) {
            cur=0;
            dist=0;
            cnt++;
        } else {
            cur+=dist*w[i];
            sum+=dist*w[i];
        }
    }
    if (cnt>2) return -1;
    return sum;
}
int main() {
    freopen("SAWMILL.INP","r",stdin);
    freopen("SAWMILL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i]>>d[i];
    long long lo=0,hi=1e9;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        long long temp=calc(mid);
        if (temp!=-1) {
            hi=mid-1;
            res=temp;
        } else lo=mid+1;
    }
    cout<<res;
}
