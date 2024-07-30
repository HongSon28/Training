#include<bits/stdc++.h>
using namespace std;
const int N=65;
int n,m,res;
long long a[N][N],b[N][N],k;
int c[N][N],h[N],l[N],r[N];
int hist(int n) {
	stack<int>st;
	int mx=0;
	for (int i=1;i<=n;i++) {
		while (!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if (st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n;i>=1;i--) {
		while (!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if (st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	for (int i=1;i<=n;i++) mx=max(mx,h[i]*(r[i]-l[i]-1));
	return mx;
}
int calc(int x,int y) {
	int ans=0;
	memset(h,0,sizeof(h));
	for (int i=1;i<=x;i++) {
		for (int j=1;j<=y;j++) {
			if (c[i][j]==1) h[j]++;
			else h[j]=0;
		}
		ans=max(ans,hist(y));
	}
	return ans;
}
int main() {
    //freopen("htab.inp","r",stdin);
    //freopen("htab.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>b[i][j];
	for (int oi=-n+1;oi<n;oi++) {
		for (int oj=-m+1;oj<m;oj++) {
			int si=1,sj=1,ei=n,ej=m;
			if (oi<0) si=-oi+1;
			else ei=n-oi;
			if (oj<0) sj=-oj+1;
			else ej=m-oj;
			for (int i=si;i<=ei;i++) {
				for (int j=sj;j<=ej;j++) {
					c[i-si+1][j-sj+1]=abs(a[i+oi][j+oj]-b[i][j]);
					c[i-si+1][j-sj+1]=(c[i-si+1][j-sj+1]<=k);
				}
			}
			res=max(res,calc(ei-si+1,ej-sj+1));
		}
	}
	cout<<res;
}
