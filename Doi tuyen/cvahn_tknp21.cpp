#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long sum[N+5];
string s;
pair<long long,long long>p[201];
int res=-1;
bool touch(int i,int j,long long d) {
    long long x=abs(p[i].first-p[j].first);
    long long y=abs(p[i].second-p[j].second);
    return max(x,y)<=d*2;
}
bool check(int m) {
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (touch(i,j,sum[m]+1)) return true;
        }
    }
    return false;
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=k;i++) sum[i]=sum[i-1]+(int)s[i]-'0';
    int lo=0,hi=k;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            hi=mid-1;
            res=mid;
        } else lo=mid+1;
    }
    cout<<res;
}
