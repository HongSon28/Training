#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int m,n,k;
long long res;
int a[N+5][N+5];
long long cnt[N+5][N+5];
long long d1[N+5][N+5];
long long d2[N+5][N+5];
int h[N+5],l[N+5],r[N+5];
void hist(int row) {
	stack<int>st;
	for (int i=1;i<=n;i++) {
		while (!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if (st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n;i>=1;i--) {
		while (!st.empty()&&h[st.top()]>h[i]) st.pop();
		if (st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	for (int i=1;i<=n;i++) {
		int v=min(i-l[i],r[i]-i);;
		d2[h[i]+1][1]++;
		d2[h[i]+1][v]-=v;
		d2[h[i]+1][v+1]+=v-1;
		int mx=max(i-l[i],r[i]-i);
		d2[h[i]+1][v]+=v;
		d2[h[i]+1][v+1]-=v;
		d2[h[i]+1][mx+1]-=v;
		d2[h[i]+1][mx+2]+=v;
		int t=v-1;
		d2[h[i]+1][mx+1]+=t;
		d2[h[i]+1][mx+2]-=t+1;
		d2[h[i]+1][mx+t+2]++;
		
		d2[row+1][1]--;
		d2[row+1][v]+=v;
		d2[row+1][v+1]-=v-1;
		d2[row+1][v]-=v;
		d2[row+1][v+1]+=v;
		d2[row+1][mx+1]+=v;
		d2[row+1][mx+2]-=v;
		d2[row+1][mx+1]-=t;
		d2[row+1][mx+2]+=t+1;
		d2[row+1][mx+t+2]--;
	}
}
void calc(int x) {
	memset(h,0,sizeof(h));
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			if (a[i][j]==x) h[j]++;
			else h[j]=0; 
		}
		hist(i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>m>>n>>k;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	calc(0);
	calc(1);
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) d2[i][j]+=d2[i-1][j];
		for (int j=1;j<=n;j++) {
			d1[i][j]=d1[i][j-1]+d2[i][j];
			cnt[i][j]=cnt[i][j-1]+d1[i][j];
			//cout<<i<<' '<<j<<' '<<d1[i][j]<<' '<<d2[i][j]<<' '<<cnt[i][j]<<endl;
			if (i*j>=k) res+=cnt[i][j]-(m-i+1)*(n-j+1);
		}
	}
	cout<<res;
}
