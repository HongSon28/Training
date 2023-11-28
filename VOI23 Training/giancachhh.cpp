#include<bits/stdc++.h>
using namespace std;
#define double float
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int N=1e3;
int n,m,k;
struct point{
	double x,y;
}p[N+5];
int par[N+5];
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
double res;
bool intersect(point a,point b,double r) {
	double dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if (dist<r+r) return true;
	return false;
}
bool dl[N+5],dr[N+5],dd[N+5],du[N+5];
bool check(double r) {
	for (int i=1;i<=k;i++) {
		par[i]=-1;
		dl[i]=dr[i]=du[i]=dd[i]=false;
	}
	for (int i=1;i<=k;i++) {
		for (int j=i+1;j<=k;j++) {
			if (intersect(p[i],p[j],r)) Union(i,j);
		}
	}
	for (int i=1;i<=k;i++) {
		int t=findroot(i);
		if (p[i].x<r) dl[t]=true;
		if (p[i].y<r) dd[t]=true;
		if (n-p[i].x<r) dr[t]=true;
		if (m-p[i].y<r) du[t]=true;
	}
	for (int i=1;i<=k;i++) {
		if (dl[i]&&dr[i]) return false;
		if (du[i]&&dd[i]) return false;
		if (du[i]&&dr[i]) return false;
		if (dl[i]&&dd[i]) return false;
	}
	return true;
} 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++) cin>>p[i].x>>p[i].y;
	double lo=0,hi=min(m,n);
	int cnt=0;
	while (hi-lo>1e-4&&++cnt<200) {
		double mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			lo=mid;
		} else hi=mid;
	}
	cout<<fixed<<res;
}