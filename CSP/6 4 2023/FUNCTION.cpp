#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int check(double m) {
    double f=a*m*m*m+b*m*m+c*m+d;
    if (f>1e-4) return 1;
    if (f<-1e-4) return -1;
    return 0;
}
float calc(float x) {
    return a*x*x*x+b*x*x+c*x+d;
}
int main() {
    freopen("FUNCTION.INP","r",stdin);
    freopen("FUNCTION.OUT","w",stdout);
    cin>>a>>b>>c>>d;
    int m;
    if (calc(1)<calc(100)) m=1;
    else m=-1;
    //cout<<m<<endl;
    double lo=-1e18,hi=1e18;
    while (hi-lo>1e-10) {
        double mid=(lo+hi)/2;
        if (check(mid)*m==1) {
            hi=mid;
        } else if (check(mid)*m==-1) {
            lo=mid;
        } else {
            cout.precision(9);
            cout<<fixed<<mid<<endl;
            return 0;
        }
    }
}
