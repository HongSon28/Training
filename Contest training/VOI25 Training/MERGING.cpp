#include<bits/stdc++.h>
using namespace std;
const int N=5000,LG=13;
int n,q;
int l[N+5],r[N+5];
int rmq[N+5][LG+5];
int get(int l,int r) {
	if (l>r) return 0;
	if (l==r) return rmq[l][0];
	int lg=__lg(r-l+1);
	return max(rmq[l][lg],rmq[r-(1<<lg)+1][lg]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for (int i=1;i<n;i++) rmq[i][0]=(l[i+1]-r[i]+1)/2;
    for (int j=1;(1<<j)<=n;j++) {
    	for (int i=1;i+(1<<j)-1<=n;i++) rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
    }	
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<get(l,r-1)<<'\n';
    }
}