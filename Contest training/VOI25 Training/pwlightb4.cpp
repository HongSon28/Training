#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
struct line {
	long long x,y,u,v;
	double d;
	bool operator < (const line &other) const {
		return d<other.d;
	}
} a[N+5];
bitset<N+5>bit[N+5];
long long res;
int ccw(long long xa,long long ya,long long xb,long long yb,long long xc,long long yc) {
	xb-=xa,yb-=ya;
	xc-=xa,yc-=ya;
	long long temp=xb*yc-yb*xc;
	if (temp>0) return 1;
	else if (temp<0) return -1;
	return 0;
} 
bool parallel(int i,int j) {
	return (a[i].v-a[i].y)*(a[j].u-a[j].x)==(a[j].v-a[j].y)*(a[i].u-a[i].x);
}
bool check(int i,int j) {
	long long temp=(a[i].v-a[i].y)*(a[j].v-a[j].y)+(a[i].u-a[i].x)*(a[j].u-a[j].x);
	if (temp!=0) return false;
	if (ccw(a[i].x,a[i].y,a[i].u,a[i].v,a[j].x,a[j].y)==ccw(a[i].x,a[i].y,a[i].u,a[i].v,a[j].u,a[j].v)) return false;
	if (ccw(a[j].x,a[j].y,a[j].u,a[j].v,a[i].x,a[i].y)==ccw(a[j].x,a[j].y,a[j].u,a[j].v,a[i].u,a[i].v)) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i].x>>a[i].y>>a[i].u>>a[i].v;
		a[i].d=(double)(a[i].v-a[i].y)/(a[i].u-a[i].x);
	}
	sort(a+1,a+1+n);
	int cur=1,mx=0,ban;
	for (int i=2;i<=n;i++) {
		if (parallel(i,i-1)) cur++;
		else {
			if (mx<cur) {
				mx=cur;
				ban=i-1;
			}
			cur=1;
		}
	}
	if (mx<cur) ban=n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (check(i,j)) {
				bit[i].set(j);
				bit[j].set(i);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (parallel(i,ban)) continue;
		if ((bit[i]&bit[0]).count()!=0) continue;
		bit[0].set(i);
		for (int j=i+1;j<=n;j++) {
			if (!parallel(i,j)) continue;
			long long temp=(bit[i]&bit[j]).count();
			//cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].u<<' '<<a[i].v<<' '<<a[j].x<<' '<<a[j].y<<' '<<a[j].u<<' '<<a[j].v<<' '<<temp<<endl;
			res+=temp*(temp-1)/2;
		}
	}
	cout<<res;
}