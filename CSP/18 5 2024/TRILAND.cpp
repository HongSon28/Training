#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,m;
long long res;
struct point{
	long long x,y;
} p[N+5];
vector<point>hull;
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
long long area(point a,point b,point c) {
	point u={b.x-a.x,b.y-a.y};
	point v={c.x-a.x,c.y-a.y};
	return u.x*v.y-u.y*v.x;
}
int main() {
	freopen("TRILAND.INP","r",stdin);
	freopen("TRILAND.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i].x>>p[i].y;
	}
	sort(p+1,p+1+n,c1);
	sort(p+2,p+1+n,c2);
	hull.push_back(p[1]);
	hull.push_back(p[2]);
	p[n+1]=p[1];
	for (int i=3;i<=n+1;i++) {
		while (hull.size()>1&&ccw(hull[hull.size()-2],hull.back(),p[i])!=1) {
			hull.pop_back();
		}
		hull.push_back(p[i]);
	}
	hull.pop_back();
	m=hull.size();
	for (int i=0;i<m;i++) {
		int k=i+2;
		for (int j=i+1;j<m;j++) {
			while (k+1<m&&area(hull[i],hull[j],hull[k])<area(hull[i],hull[j],hull[k+1]))
				k++;
			res=max(res,area(hull[i],hull[j],hull[k]));
		}
	}
	cout<<res/2;
	if (res%2==0) cout<<".0";
	else cout<<".5";
}