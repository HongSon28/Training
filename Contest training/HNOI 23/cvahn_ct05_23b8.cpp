#include<bits/stdc++.h>
using namespace std;
const int N=30,maxN=100;
int n;
int x[N+5],y[N+5],h[N+5];
double d[maxN+5][maxN+5];
double inf=1e9;
pair<int,int>trace[maxN+5][maxN+5];
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
        Point t2={x[i]+h[i],y[i]};
        Point t3={x[i],y[i]+h[i]};
        Point t4={x[i]+h[i],y[i]+h[i]};
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
    d[0][0]=0;
    pq.push({0,0,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        if (t.w!=d[t.x][t.y]) continue;
        for (auto p:vert) {
            if (check({t.x,t.y},p)&&dist({t.x,t.y},p)+t.w<d[p.first][p.second]) {
                d[p.first][p.second]=t.w+dist({t.x,t.y},p);
                trace[p.first][p.second]=make_pair(t.x,t.y);
                //cout<<t.x<<' '<<t.y<<' '<<p.first<<' '<<p.second<<' '<<d[p.first][p.second]<<endl;
                pq.push({p.first,p.second,d[p.first][p.second]});
            }
        }
    }
    //cout<<check({0,0},{5,10});
    cout.precision(3);
    cout<<fixed<<d[100][100]<<endl;
    int tx=100,ty=100;
    vector<pair<int,int>>v;
    while (tx!=0||ty!=0) {
        int temp1=trace[tx][ty].first,temp2=trace[tx][ty].second;
        v.push_back({temp1,temp2});
        tx=temp1,ty=temp2;
    }
    reverse(v.begin(),v.end());
    for (int i=1;i<v.size();i++) cout<<v[i].first<<' '<<v[i].second<<endl;
//    cout<<trace[0][0].first<<' '<<trace[0][0].second<<'\n'<<trace[5][10].first<<' '<<trace[5][10].second<<'\n';
//    cout<<trace[20][20].first<<' '<<trace[20][20].second<<'\n'<<trace[95][90].first<<' '<<trace[95][90].second<<'\n';
//    cout<<trace[100][100].first<<' '<<trace[100][100].second;
}
int main() {
    freopen("VVCAN.INP","r",stdin);
    freopen("VVCAN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x[i]>>y[i]>>h[i];
        vert.push_back({x[i],y[i]});
        vert.push_back({x[i]+h[i],y[i]});
        vert.push_back({x[i],y[i]+h[i]});
        vert.push_back({x[i]+h[i],y[i]+h[i]});
    }
    vert.push_back({100,100});
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
