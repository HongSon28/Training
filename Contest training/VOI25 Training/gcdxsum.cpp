#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N+5];
int rmq[N+5][21];
long long sum[N+5],res;
int get(int l,int r) {
	if (l==r) return a[l];
	r--;
	int lg=__lg(r-l+1);
	return __gcd(rmq[l][lg],rmq[r-(1<<lg)+1][lg]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<n;i++) rmq[i][0]=__gcd(a[i],a[i+1]);
    for (int j=1;(1<<j)<n;j++) {
    	for (int i=1;i+(1<<j)-1<n;i++) rmq[i][j]=__gcd(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
    }
    int last=-1;
    for (int i=1;i+k-1<=n;i++) {
    	int j=i+k-1;
    	int cur=get(i,j);
    	if (cur==last) continue;
    	last=cur;
    	while (j<=n) {
    		cur=get(i,j);
    		int ans=j,lo=j+1,hi=n;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (get(i,mid)==cur){
    				ans=mid;
    				lo=mid+1;
    			} else hi=mid-1;
    		}
    		j=ans;
    		res=max(res,(sum[j]-sum[i-1])*cur);
    		j++;
    	}
    }
    cout<<res;
}