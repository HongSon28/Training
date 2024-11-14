#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,p,q,m;
int l[N+5],r[N+5],lst[N+5],frs[N+5],res;
int ans[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>p>>q>>m;
    for (int i=0;i<=N;i++) {
    	frs[i]=N+5;
    	lst[i]=-1;
    }
    for (int t=1;t<=m;t++) {
    	int i,v;
    	cin>>i>>v;
    	lst[v]=max(lst[v],i);
    	frs[v]=min(frs[v],i);
    }
    for (int i=1;i<=n;i++) {
    	l[i]=max(l[i-1]+p,lst[i]);
    	r[i]=min(r[i-1]+q,frs[i+1]-1);
    	//cout<<l[i]<<' '<<r[i]<<endl;
    	if (l[i]<=n) res=i;
    	else break;
    }
    r[res]=n;
    cout<<res<<'\n';
    int cur=n;
    for (int i=res;i>=1;i--) {
    	int st=min({cur-p+1,frs[i],r[i-1]+1});
    	while (cur>=st) {
    		ans[cur]=i;
    		cur--;
    	}
    }
    while (cur>=1) {
    	ans[cur]=1;
    	cur--;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
}