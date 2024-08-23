#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
vector<vector<int>>a,b;
int h[N+5],l[N+5],r[N+5];
int res;
void hist(int lo,int hi) {
	stack<int>st;
	for (int i=lo;i<=hi;i++) {
		while (!st.empty()&&h[i]<=h[st.top()]) st.pop();
		if (st.empty()) l[i]=lo;
		else l[i]=st.top()+1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=hi;i>=lo;i--) {
		while (!st.empty()&&h[i]<=h[st.top()]) st.pop();
		if (st.empty()) r[i]=hi;
		else r[i]=st.top()-1;
		st.push(i);
	}
	for (int i=lo;i<=hi;i++) res=max(res,h[i]*(r[i]-l[i]+1));
}
void calc(int row) {
	int last=1;
	for (int i=2;i<=m;i++) {
		if (a[row][i-1]==a[row][i]) {
			hist(last,i-1);
			last=i;
		}
	}
	hist(last,m);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    a.resize(n+1);
    b.resize(n+1);
    for (int i=1;i<=n;i++) {
    	a[i].resize(m+1);
    	for (int j=1;j<=m;j++) {
    		cin>>a[i][j];
    		//cout<<b[i][j]<<' ';
    	}
    	//cout<<endl;
    }	
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		if (i>=2&&a[i][j]!=a[i-1][j]) h[j]++;
    		else h[j]=1;
    		//cout<<h[j]<<' ';
    	}
    	//cout<<endl;
    	calc(i);
    }
    cout<<res;
}