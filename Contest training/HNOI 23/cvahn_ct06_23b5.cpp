#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long a[N+5],d[N+5];
int main() {
    freopen("THICHAY.INP","r",stdin);
    freopen("THICHAY.OUT","w",stdout);
    long long n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<long long>());
    d[0]=a[0]+1;
    for (long long i=1;i<n;i++) {
        long long temp=a[i]+i+1;
        d[i]=max(d[i-1],temp);
    }
    long long res=1;
    for (int i=1;i<n;i++) {
        if (a[i]+n>=d[i-1]) res++;
    }
    cout<<res;
}
