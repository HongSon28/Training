#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
long long x[101],y[101],r[101];
bool check(long long r2) {
    for (int i=0;i<n;i++) {
        float t1=(x[i]-a)*(x[i]-a);
        float t2=(y[i]-b)*(y[i]-b);
        float t3=sqrt(t1+t2);
        float t4=r[i]+r2;
        if (t3<=t4) return false;
    }
    return true;
}
int main() {
    cin>>n>>a>>b;
    for (int i=0;i<n;i++) {
        cin>>x[i]>>y[i]>>r[i];
    }
    long long lo=0,hi=1e18,res=0;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        //cout<<lo<<' '<<hi<<' '<<mid<<endl;
        if (check(mid)==true) {
            res=max(res,mid);
            lo=mid+1;
        }
        else {
            hi=mid-1;
        }
    }
     cout<<res;
}
