#include<bits/stdc++.h>
using namespace std;
const int N=1000;
struct point {
    long long x,y,id;
    bool operator < (const point &other) const {
        if (x!=other.x) return x<other.x;
        return y<other.y;
    }
    bool operator == (const point &other) const {
        return (x==other.x&&y==other.y&&id==other.id);
    }
};
int res[N+5];
bool ccw(point a,point b,point c) {
    return (b.x-a.x) *(c.y-a.y)-(c.x-a.x)*(b.y-a.y)>0;
}
int n,phase=1;
vector<point>p,hull;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        long long x,y;
        cin>>x>>y;
        p.push_back({x,y,i});
    }
    int cnt=n;
    sort(p.begin(),p.end());
    while (cnt>0&&phase<=4) {
        int st;
        for (int i=0;i<n;i++) {
            if (res[p[i].id]==0) {
                hull.push_back(p[i]);
                st=i+1;
                res[p[i].id]=phase;
                break;
            }
        }
        for (int i=st;i<n;i++) {
            if (res[p[i].id]!=0) continue;
            while (hull.size()>=2&&ccw(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
            hull.push_back(p[i]);
        }
        for (int i=n-2;i>=0;i--) {
            if (res[p[i].id]!=0) continue;
            while (hull.size()>=2&&ccw(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
            hull.push_back(p[i]);
        }
        while (!hull.empty()) {
            if (res[hull.back().id]==0) cnt--;
            res[hull.back().id]=phase;
            hull.pop_back();
        }
        phase++;
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}
/*
16
8 2
2 4
17 4
6 5
8 7
11 9
15 10
12 18
5 16
4 20
15 18
7 15
6 14
11 13
12 13
13 14
*/
