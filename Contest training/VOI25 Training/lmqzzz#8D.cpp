#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
long long n,m;
long long a[N+5],b[N+5];
long long res;
set<pair<int,int>>row[N+5],col[N+5],diag1[N+5],diag2[N+5];
bool frow[N+5],fcol[N+5],fd1[N+5],fd2[N+5];
void calcrow(int i,int j) { //x = a[i]
	if (a[j]==a[i]) {
		frow[i]=true;
		return;
	}
	row[i].insert({a[i],b[j]});
	if (a[i]-a[j]+b[j]>=1&&a[i]-a[j]+b[j]<=n) row[i].insert({a[i],a[i]-a[j]+b[j]});
	if (a[j]+b[j]-a[i]>=1&&a[j]+b[j]-a[i]<=n) row[i].insert({a[i],a[j]+b[j]-a[i]});
}
void calccol(int i,int j) { //y = b[i]
	if (b[i]==b[j]) {
		fcol[i]=true;
		return;
	}
	col[i].insert({a[j],b[i]});
	if (a[j]+b[j]-b[i]>=1&&a[j]+b[j]-b[i]<=n) col[i].insert({a[j]+b[j]-b[i],b[i]});
	if (a[j]-b[j]+b[i]>=1&&a[j]-b[j]+b[i]<=n) col[i].insert({a[j]-b[j]+b[i],b[i]});
}
void calcdiag1(int i,int j) { //x - y = a[i] - b[i]
	if (a[i]-b[i]==a[j]-b[j]) {
		fd1[i]=true;
		return;
	}
	if (a[j]-a[i]+b[i]>=1&&a[j]-a[i]+b[i]<=n) diag1[i].insert({a[j],a[j]-a[i]+b[i]});
	if (a[i]-b[i]+b[j]>=1&&a[i]-b[i]+b[j]<=n) diag1[i].insert({a[i]-b[i]+b[j],b[j]});
	long long t1=a[i]-b[i],t2=a[j]+b[j];
	if ((t1+t2)%2==0) {
		long long x=(t1+t2)/2,y=(t2-t1)/2;
		if (x>=1&&y>=1&&x<=n&&y<=n) diag1[i].insert({x,y});
	}
}
void calcdiag2(int i,int j) { //x + y = a[i] + b[i]
	if (a[i]+b[i]==a[j]+b[j]) {
		fd2[i]=true;
		return;
	}
	if (a[i]+b[i]-a[j]>=1&&a[i]+b[i]-a[j]<=n) diag2[i].insert({a[j],a[i]+b[i]-a[j]});
	if (a[i]+b[i]-b[j]>=1&&a[i]+b[i]-b[j]<=n) diag2[i].insert({a[i]+b[i]-b[j],b[j]});
	long long t1=a[i]+b[i],t2=a[j]-b[j];
	if ((t1+t2)%2==0) {
		long long x=(t1+t2)/2,y=(t1-t2)/2;
		if (x>=1&&y>=1&&x<=n&&y<=n) diag2[i].insert({x,y});
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=m;i++) {
    	long long t=a[i]-b[i];
    	long long cd1=min(t+n,n)-max(1ll,t+1)+1;	
    	t=a[i]+b[i];
    	long long cd2=min(t-1,n)-max(t-n,1ll)+1;
    	for (int j=1;j<i;j++) {
    		if ((int)row[i].size()<n&&!frow[i]) calcrow(i,j);
    		if ((int)col[i].size()<n&&!fcol[i]) calccol(i,j);
    		if ((int)diag1[i].size()<cd1&&!fd1[i]) calcdiag1(i,j);
    		if ((int)diag2[i].size()<cd2&&!fd2[i]) calcdiag2(i,j);
    	}
    	//if (i==3) cout<<cd1<<' '<<cd2<<' '<<row[i].size()<<' '<<col[i].size()<<' '<<diag1[i].size()<<' '<<diag2[i].size()<<endl;
    	if (!frow[i]) {
    		res+=n-(int)row[i].size();
    		//if (i==3) cout<<res<<' ';
    	}
    	if (!fcol[i]) {
    		res+=n-(int)col[i].size();
    		if (!col[i].count({a[i],b[i]})) res--; 
    		//if (i==3) cout<<res<<' ';
    	}
    	if (!fd1[i]) {
    		res+=cd1-(int)diag1[i].size();
    		if (!diag1[i].count({a[i],b[i]})) res--;
    		//if (i==3) cout<<res<<' ';
    	}
    	if (!fd2[i]) {
    		res+=cd2-(int)diag2[i].size();
    		if (!diag2[i].count({a[i],b[i]})) res--; 
    		//if (i==3) cout<<res<<' ';
    	}
    	//cout<<res<<endl;
    }	
    cout<<n*n-res;
}