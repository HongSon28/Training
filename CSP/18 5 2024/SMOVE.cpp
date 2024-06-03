#include<bits/stdc++.h>
using namespace std;
struct point{
	long long x,y;
} a,b,m,n;
double dist(point a,point b) {
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int ccw(point a,point b,point c) {
	long long temp=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
	if (temp==0) return 0;
	if (temp>0) return 1;
	return -1;
}
bool in() {
	int t=ccw(a,b,m);
	if (t==0) {
		if ((a.x<=m.x&&m.x<=b.x)||(a.x>=m.x&&m.x>=b.x)) return true;
	}
	t=ccw(a,b,n);
	if (t==0) {
		if ((a.x<=n.x&&n.x<=b.x)||(a.x>=n.x&&n.x>=b.x)) return true;
	}
	return false;
}
bool check() {
	bool p1=false,p2=false;
	int t1=ccw(m,n,a),t2=ccw(m,n,b);
	if (t1>=0&&t2<=0) p1=true;
	if (t1<=0&&t2>=0) p1=true;
	t1=ccw(a,b,m),t2=ccw(a,b,n);
	if (t1>=0&&t2<=0) p2=true;
	if (t1<=0&&t2>=0) p2=true;
	return (p1&&p2);
}
int main() {
	freopen("SMOVE.INP","r",stdin);
	freopen("SMOVE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a.x>>a.y>>b.x>>b.y>>m.x>>m.y>>n.x>>n.y;
    cout.precision(4);
	if (in()||!check()) cout<<fixed<<dist(m,n);
	else cout<<fixed<<min(dist(m,a)+dist(a,n),dist(m,b)+dist(b,n));	
}