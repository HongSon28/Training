#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
struct point {
    long long x,y;
    bool operator < (const point &other) const {
        if (x!=other.x) return x<other.x;
        return y<other.y;
    }
};
vector<point>p,hull;
bool ccw(point a,point b,point c) {
    return (b.x-a.x) *(c.y-a.y)-(c.x-a.x)*(b.y-a.y)>0;
}
double v,s;
double dist(point a,point b) {
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
double calc(point a,point b,point c) {
    double x=dist(a,b);
    double y=dist(a,c);
    double z=dist(b,c);
    double p=(x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}
int main() {
    freopen("BAOLOI.INP","r",stdin);
    freopen("BAOLOI.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        long long x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    sort(p.begin(),p.end());
    hull.push_back(p[0]);
    for (int i=1;i<n;i++) {
        while (hull.size()>=2&&ccw(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
        hull.push_back(p[i]);
    }
    for (int i=n-2;i>=0;i--) {
        while (hull.size()>=2&&ccw(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
        hull.push_back(p[i]);
    }
    if (n>1) hull.pop_back();
    cout<<hull.size()<<' ';
    v=dist(hull[0],hull.back());
    for (int i=0;i<hull.size()-1;i++) v+=dist(hull[i],hull[i+1]);
    for (int i=1;i<hull.size()-1;i++) s+=calc(hull[0],hull[i],hull[i+1]);
    cout.precision(3);
    cout<<fixed<<v<<' '<<s;
}
