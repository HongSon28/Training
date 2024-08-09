#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int m,n,res;
int l[N+5],r[N+5],h[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		int temp;
    		cin>>temp;
    		if (temp==1) h[j]++;
    		else h[j]=0;
    	}
    	for (int j=1;j<=n;j++) {
    		int t=j-1;
    		while (t>0&&h[t]>=h[j]) t=l[t];
    		l[j]=t;
    	}
    	for (int j=n;j>=1;j--) {
    		int t=j+1;
    		while (t<=n&&h[t]>=h[j]) t=r[t];
    		r[j]=t;
    		res=max(res,h[j]*(r[j]-l[j]-1));
    	}
    }
    cout<<res;
}