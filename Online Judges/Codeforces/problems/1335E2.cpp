#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
int nxt[N+5],lst[N+5];
int npos[205],lpos[205];
int cnt[205][N+5];
int res;
int calc(int l,int r) {
	int ans=0;
	if (l>r) return 0;
	for (int i=1;i<=200;i++) ans=max(ans,cnt[i][r]-cnt[i][l-1]);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	res=0;
    	for (int i=1;i<=200;i++) lpos[i]=npos[i]=0;
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		for (int j=1;j<=200;j++) cnt[j][i]=cnt[j][i-1]+(a[i]==j);
    		nxt[i]=lst[i]=0;
    	}
    	for (int i=1;i<=n;i++) {
    		if (lpos[a[i]]!=0) nxt[lpos[a[i]]]=i;
    		lpos[a[i]]=i;
    	}
    	for (int i=n;i>=1;i--) {
    		if (npos[a[i]]!=0) lst[npos[a[i]]]=i;
    		npos[a[i]]=i;
    	}
    	//for (int i=1;i<=n;i++) cout<<i<<' '<<nxt[i]<<' '<<lst[i]<<endl;
    	//cout<<endl;
    	for (int i=1;i<=200;i++) {
    		res=max(res,cnt[i][n]);
    		int l=npos[i],r=lpos[i];
    		if (l==0&&r==0) continue;
    		int cur=2;
    		while (l<=r&&r>0) {
    			if (l==r) cur--;
    			res=max(res,cur+calc(l+1,r-1));
    			//cout<<l<<' '<<r<<' '<<nxt[l]<<' '<<lst[r]<<' '<<cur+calc(l+1,r-1)<<endl;
    			cur+=2;
    			l=nxt[l],r=lst[r];
    		}
    	}
    	cout<<res<<'\n';
    }
}
