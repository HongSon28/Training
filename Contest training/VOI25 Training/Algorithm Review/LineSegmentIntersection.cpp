#include<bits/stdc++.h>
using namespace std;
int t;
struct Point{
	long long x,y;
} a,b,c,d;	
int cross(Point x,Point y,Point z) {
	Point a={y.x-x.x,y.y-x.y};
	Point b={z.x-x.x,z.y-x.y};
	long long t=a.x*b.y-a.y*b.x;
	if (t>0) return 1;
	if (t<0) return -1;
	return 0;
}
bool mid(Point x,Point y,Point z) {
	return (((x.x<=y.x&&y.x<=z.x)||(x.x>=y.x&&y.x>=z.x))&&((x.y<=y.y&&y.y<=z.y)||(x.y>=y.y&&y.y>=z.y)));
}
bool solve() {
	if (cross(a,b,c)==0&&mid(a,c,b)) return true;
	if (cross(a,b,d)==0&&mid(a,d,b)) return true;
	if (cross(c,d,a)==0&&mid(c,a,d)) return true;
	if (cross(c,d,b)==0&&mid(c,b,d)) return true;
	return (cross(a,b,c)!=cross(a,b,d)&&cross(c,d,a)!=cross(c,d,b)); 
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    	if (solve()) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }	
}
