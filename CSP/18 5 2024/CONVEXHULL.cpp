#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct point{
	long long x,y;
} p[N+5];
int ccw(point a,point b,point c) {
	long long temp=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
	if (temp==0) return 0;
	if (temp>0) return 1;
	return -1;
}
bool c1(point a,point b) {
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
bool c2(point a,point b) {
	if (ccw(p[1],a,b)==1) return true;
	return false;
}
bool mid(point a,point b,point c) {
	if (a.x<=b.x&&b.x<=c.x) return true;
	if (a.x>=b.x&&b.x>=c.x) return true;
	return false;
}
int n;
vector<point>hull;
unsigned long long res;
long long calc(point a,point b) {
	return a.x*b.y-a.y*b.x;
}
int main() {
	freopen("CONVEXHULL.INP","r",stdin);
	freopen("CONVEXHULL.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,c1);
	sort(p+2,p+1+n,c2);
	//for (int i=1;i<=n;i++) cout<<p[i].x<<' '<<p[i].y<<endl;
	hull.push_back(p[1]);
	hull.push_back(p[2]);
	p[n+1]=p[1];
	for (int i=3;i<=n+1;i++) {
		bool t=true;
		while (hull.size()>1&&ccw(hull[hull.size()-2],hull.back(),p[i])!=1) {
			if (ccw(hull[hull.size()-2],hull.back(),p[i])==-1) hull.pop_back();
			else if (mid(hull[hull.size()-2],hull.back(),p[i])) hull.pop_back();
			else {
				t=false;
				break;
			}
		}
		if (t) hull.push_back(p[i]);
	}
	for (int i=0;i<hull.size()-1;i++) {
		res+=calc(hull[i],hull[i+1]);
	}
	cout<<hull.size()-1<<'\n';
	if (res%2==0) cout<<res/2<<".0"<<'\n';
	else cout<<res/2<<".5"<<'\n'; 
	for (int i=0;i<hull.size()-1;i++) cout<<hull[i].x<<' '<<hull[i].y<<'\n';
}