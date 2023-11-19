#include<bits/stdc++.h>
using namespace std;
const int maxN=1e4,N=200;
int n;
int x[N+5],y[N+5],u[N+5],v[N+5],x_1,x_2,y_1,y_2;
double d[maxN+5][maxN+5];
double inf=1e9;
vector<pair<int,int>>vert;
struct dat{
    int x,y;
    double w;
    bool operator < (const dat &other) const {
        return w>other.w;
    }
};
priority_queue<dat>pq;
struct Point{
    int x,y;
};
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 == 0 && onSegment(p1, p2, q1)) return false;
    if (o2 == 0 && onSegment(p1, q2, q1)) return false;
    if (o3 == 0 && onSegment(p2, p1, q2)) return false;
    if (o4 == 0 && onSegment(p2, q1, q2)) return false;
    if (o1 != o2 && o3 != o4)
        return true;
    return false;
}
bool check(pair<int,int>xx,pair<int,int>yy) {
    Point p1={xx.first,xx.second};
    Point q1={yy.first,yy.second};
    for (int i=1;i<=n;i++) {
        Point t1={x[i],y[i]};
        Point t2={x[i],v[i]};
        Point t3={u[i],y[i]};
        Point t4={u[i],v[i]};
        if (doIntersect(p1,q1,t1,t2)||doIntersect(p1,q1,t1,t3)||doIntersect(p1,q1,t2,t4)||doIntersect(p1,q1,t3,t4)) {
            //cout<<i<<endl;
            return false;
        }
        if (orientation(p1,t1,q1)==0&&onSegment(p1,t1,q1)&&orientation(p1,t4,q1)==0&&onSegment(p1,t4,q1)) {return false;}
        if (orientation(p1,t2,q1)==0&&onSegment(p1,t2,q1)&&orientation(p1,t3,q1)==0&&onSegment(p1,t3,q1)) {return false;}
    }
    return true;
}
double dist(pair<int,int>xx,pair<int,int>yy) {
    double t=(xx.first-yy.first)*(xx.first-yy.first)+(xx.second-yy.second)*(xx.second-yy.second);
    return sqrt(t);
}
void dij() {
    for (int i=0;i<=maxN;i++)
        for (int j=0;j<=maxN;j++)
            d[i][j]=inf;
    d[x_1][y_1]=0;
    pq.push({x_1,y_1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        if (t.w!=d[t.x][t.y]) continue;
        for (auto p:vert) {
            if (check({t.x,t.y},p)&&dist({t.x,t.y},p)+t.w<d[p.first][p.second]) {
                d[p.first][p.second]=t.w+dist({t.x,t.y},p);
                pq.push({p.first,p.second,d[p.first][p.second]});
            }
        }
    }
    //cout<<check({0,0},{5,10});
    cout.precision(3);
    cout<<fixed<<d[x_2][y_2]<<endl;
}
int main() {
    freopen("DDNN.INP","r",stdin);
    freopen("DDNN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cin>>x_1>>y_1>>x_2>>y_2;
    for (int i=1;i<=n;i++) {
        cin>>x[i]>>y[i]>>u[i]>>v[i];
        vert.push_back({x[i],y[i]});
        vert.push_back({x[i],v[i]});
        vert.push_back({u[i],v[i]});
        vert.push_back({u[i],y[i]});
    }
    vert.push_back({x_2,y_2});
    //cout<<check({5,10},{20,20});
    dij();
}
/*
5
5 5 5
5 15 5
15 10 5
15 20 5
90 90 5
*/
