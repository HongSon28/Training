#include<bits/stdc++.h>
using namespace std;
int n,l;
long double res;
long double a[1000000];
bool check (double m) {
    long double left=a[0]-m,right=a[0]+m;
    if (left>0) return false;
    for (int i=1;i<n;i++) {
        if (a[i]-m>right) return false;
        else {
            left=a[i]-m;
            right=a[i]+m;
        }
    }
    if (right<l) return false;
    return true;
}
int main() {
    cin>>n>>l;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    long double lo=1,hi=l+1;
    while (hi-lo>1e-7) {
        long double mid=(lo+hi)/2;
        if (check(mid)==true) {
            hi=mid;
            res=mid;
        } else {
            lo=mid;
        }
        //cout<<lo<<' '<<hi<<' '<<mid<<endl;
    }
    cout.precision(6);
    cout<<fixed<<res;
}
