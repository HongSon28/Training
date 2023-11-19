#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
double w,h;
struct word {
    double width,height;
    bool operator < (const word &other) const {
        return height<other.height;
    }
};
word a[N+5];
double res;
double lo,hi;
bool check(double m) {
    double cur_w=w,cur_h=h;
    for (int i=1;i<=n;i++) {
        if (a[i].height*m==a[i-1].height*m) {
            cur_w-=a[i].width*m;
            if (cur_w<0) {
                cur_h-=a[i].height*m;
                cur_w=w-a[i].width*m;
            }
            if (cur_h<0) return false;
            if (cur_w<0) return false;
        } else {
            cur_h-=a[i].height*m;
            cur_w=w-a[i].width*m;
            if (cur_h<0) return false;
            if (cur_w<0) return false;
        }
    }
    return true;
}
int main() {
    freopen("ADVERT.INP","r",stdin);
    freopen("ADVERT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>w>>h;
    lo=0,hi=1e9;
    for (int i=1;i<=n;i++) cin>>a[i].width>>a[i].height;
    sort(a+1,a+1+n);
    while (hi-lo>=1e-7) {
        double mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid;
        } else hi=mid;
    }
    cout.precision(6);
    cout<<fixed<<res;
}
