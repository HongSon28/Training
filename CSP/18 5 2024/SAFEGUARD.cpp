#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct point{
	long long x,y;
} p[N+5],q[N+5];
int ccw(point a,point b,point c) {
	long long temp=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
	if (temp==0) return 0;
	if (temp>0) return 1;
	return -1;
}
long long d(point a,point b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool c1(point a,point b) {
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
bool c2(point a,point b) {
	if (ccw(p[1],a,b)==1) return true;
	if (ccw(p[1],a,b)==0) return d(p[1],a)<d(p[1],b);
	return false;
}
int n,m,res;
vector<point>hull;
bool check(point x) {
	for (int i=0;i<(int)hull.size()-1;i++) {
		if (ccw(hull[i],hull[i+1],x)==-1) return false;
	}
	return true;
}
int main() {
	freopen("SAFEGUARD.INP","r",stdin);
	freopen("SAFEGUARD.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i].x>>p[i].y;
	}
	cin>>m;
	for (int i=1;i<=m;i++) cin>>q[i].x>>q[i].y;
	sort(p+1,p+1+n,c1);
	sort(p+2,p+1+n,c2);
	hull.push_back(p[1]);
	hull.push_back(p[2]);
	p[n+1]=p[1];
	//cout<<p[1].x<<' '<<p[1].y<<endl;
	//cout<<p[2].x<<' '<<p[2].y<<endl;
	for (int i=3;i<=n+1;i++) {
		//cout<<p[i].x<<' '<<p[i].y<<endl;
		bool t=true;
		while (hull.size()>1&&ccw(hull[hull.size()-2],hull.back(),p[i])!=1) {
			hull.pop_back();
		}
		hull.push_back(p[i]);
	}
	if (hull.size()-1<3) {
		cout<<0;
		return 0;
	}
	//for (int i=0;i<(int)hull.size()-1;i++) cout<<"("<<hull[i].x<<','<<hull[i].y<<")"<<endl;
	for (int i=1;i<=m;i++) res+=check(q[i]);
	cout<<res;
}