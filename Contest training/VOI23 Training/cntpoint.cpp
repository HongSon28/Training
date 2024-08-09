#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long res;
long long xa[N+5],xb[N+5],ya[N+5],yb[N+5],a[N+5],b[N+5],c[N+5];
bool mid(long long xa,long long ya,long long xb,long long yb,long long xc,long long yc) {
    int cnt=0;
    if ((xa<=xb&&xb<=xc)||(xa>=xb&&xb>=xc)) cnt++;
    if ((ya>=yb&&yb>=yc)||(ya<=yb&&yb<=yc)) cnt++;
    return (cnt==2);
}
pair<long long,long long>point(int i,int j) {
	long long d=a[i]*b[j]-a[j]*b[i];
	long long dx=c[j]*b[i]-c[i]*b[j];
	long long dy=c[i]*a[j]-c[j]*a[i];
	if (d==0||dx%d!=0||dy%d!=0) return {-1000000000,-1000000000};
	return {dx/d,dy/d};
}
map<pair<long long,long long>,set<int>>mp;
void check(int i,int j) {
	pair<long long,long long>p=point(i,j),p2={-1000000000,-1000000000};
	if (p==p2) return;
	long long xp=p.first,yp=p.second;
	if (a[i]*xp+b[i]*yp+c[i]!=0) return;
	if (a[j]*xp+b[j]*yp+c[j]!=0) return;
	if (!mid(xa[i],ya[i],xp,yp,xb[i],yb[i])||!mid(xa[j],ya[j],xp,yp,xb[j],yb[j])) return;
	mp[{xp,yp}].insert(i);
	mp[{xp,yp}].insert(j);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>xa[i]>>ya[i]>>xb[i]>>yb[i];
    	res+=__gcd(abs(xa[i]-xb[i]),abs(ya[i]-yb[i]))+1;
    	a[i]=yb[i]-ya[i];
    	b[i]=xa[i]-xb[i];
    	c[i]=xb[i]*ya[i]-xa[i]*yb[i];
    }
    for (int i=1;i<=n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		check(i,j);
    	}
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
    	res-=i->second.size()-1;
    }
    cout<<res;
}