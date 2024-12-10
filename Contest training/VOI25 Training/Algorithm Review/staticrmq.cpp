#include<bits/stdc++.h>
using namespace std;
const int N=5e5,LG=19;
int n,q;
int a[N+5];
int rmq[N+5][LG+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	rmq[i][0]=a[i];
    }
    for (int i=1;(1<<i)<=n;i++) {
    	for (int j=1;j+(1<<i)-1<=n;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
    }
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	l++;
    	int k=__lg(r-l+1);
    	cout<<min(rmq[l][k],rmq[r-(1<<k)+1][k])<<'\n';
    }
}