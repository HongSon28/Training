#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int par[N+5];
pair<long long,long long>p1[N+5],p2[N+5],p3[N+5];
int findroot(int u) {
	if (par[u]<0) return u;
	return par[u]=findroot(par[u]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
long long ccw(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3) {
	long long a1=p2.first-p1.first;
	long long b1=p2.second-p1.second;
	long long a2=p3.first-p2.first;
	long long b2=p3.second-p2.second;
	long long t=a1*b2-a2*b1;
	if (t==0) return 0;
	if (t<0) return -1;
	return 1;
}
bool inside(int i,pair<long long,long long>p) {
	long long t1=ccw(p1[i],p2[i],p);
	long long t2=ccw(p2[i],p3[i],p);
	long long t3=ccw(p3[i],p1[i],p);
	if (t1>=0&&t2>=0&&t3>=0) return true;
	if (t1<=0&&t2<=0&&t3<=0) return true;
	return false;
}
bool mid(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3) {
	return (p1.first<=p3.first&&p3.first<=p2.first&&p1.second<=p3.second&&p3.second<=p2.second);
}
bool inter(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3,pair<long long,long long>p4) {
	long long d=(p4.second-p3.second)*(p2.first-p1.first)-(p4.first-p3.first)*(p2.second-p1.second);
	long long u=(p4.first-p3.first)*(p1.second-p3.second)-(p4.second-p3.second)*(p1.first-p3.first);
	long long v=(p2.first-p1.first)*(p1.second-p3.second)-(p2.second-p1.second)*(p1.first-p3.first);
	if (d<0) {
		d=-d;
		u=-u;
		v=-v;
	}
	if (d==0&&u==0&v==0) {
		return (mid(p1,p2,p3)||mid(p1,p2,p4)||mid(p3,p4,p1)||mid(p3,p4,p2));
	}
	if (0<=u&&u<=d&&0<=v&&v<=d) {
		return true;
	} else return false;
}
bool check(int i,int j) {
	if (inside(i,p1[j])) return true;
	if (inside(i,p2[j])) return true;
	if (inside(i,p3[j])) return true;
	
	if (inter(p1[i],p2[i],p1[j],p2[j])) return true;
	if (inter(p1[i],p2[i],p2[j],p3[j])) return true;
	if (inter(p1[i],p2[i],p3[j],p1[j])) return true;
	if (inter(p2[i],p3[i],p1[j],p2[j])) return true;
	if (inter(p2[i],p3[i],p2[j],p3[j])) return true;
	if (inter(p2[i],p3[i],p3[j],p1[j])) return true;
	if (inter(p3[i],p1[i],p1[j],p2[j])) return true;
	if (inter(p3[i],p1[i],p2[j],p3[j])) return true;
	if (inter(p3[i],p1[i],p3[j],p1[j])) return true;
	
	return false;	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>n;
    int res=n;
    for (int i=1;i<=n;i++) cin>>p1[i].first>>p1[i].second>>p2[i].first>>p2[i].second>>p3[i].first>>p3[i].second;
    for (int i=1;i<n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		if (check(i,j)||check(j,i)) {
    			//cout<<i<<' '<<j<<endl;
    			if (findroot(i)!=findroot(j)) {
    				Union(i,j);
    				res--;
    			}
    		}
    	}
    }
    cout<<res;
}