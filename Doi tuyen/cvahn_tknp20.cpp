#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,res;
int c[N+5],t[N+5],l[N+5],r[N+5];
bool check(int mx) {
    for (int i=1;i<=n;i++) l[i]=r[i]=0;
    for (int i=1;i<=n;i++) {
        l[max(1,c[i]-mx/t[i])]++;
        r[min(n,c[i]+mx/t[i])]++;
    }
    for (int i=1;i<=n;i++) {
        l[i]+=l[i-1];
        r[i]+=r[i-1];
        if (l[i]<i||r[i]>i) return false;
    }
    return true;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i]>>t[i];
    int lo=0,hi=1e8;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
