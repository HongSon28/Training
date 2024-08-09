#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SZ=316;
int n,q,nB,id;
int a[N+5];
vector<int>cprs;
int pos[N+5],last[N+5];
int fl[SZ+5][N+5],fr[SZ+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	nB=n/SZ;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cprs.push_back(a[i]);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	for (int i=1;i<=nB;i++) {
		int st=(i-1)*SZ+1;
		id++;
		for (int j=st;j<=n;j++) {
			fr[i][j]=fr[i][j-1];
			if (last[a[j]]==id) fr[i][j]=max(fr[i][j],j-pos[a[j]]);
			else {
				last[a[j]]=id;
				pos[a[j]]=j;
			}
		}
	}
	for (int i=nB;i>=1;i--) {
		int st=i*SZ;
		id++;
		for (int j=st;j>=1;j--) {
			fl[i][j]=fl[i][j+1];
			if (last[a[j]]==id) fl[i][j]=max(fl[i][j],pos[a[j]]-j);
			else {
				last[a[j]]=id;
				pos[a[j]]=j;
			}
		}
	}
	while (q--) {
		int res=0;
		int l,r;
		cin>>l>>r;
		int iL=(l+SZ-1)/SZ,iR=(r+SZ-1)/SZ;
		res=max(fr[iL+1][r],fl[iR-1][l]);
		id++;
		for (int i=l;i<=min(iL*SZ,r);i++) {
			if (last[a[i]]==id) res=max(res,i-pos[a[i]]);
			else {
				last[a[i]]=id;
				pos[a[i]]=i;
			}
		}
		for (int i=max(l,(iR-1)*SZ+1);i<=r;i++) {
			if (last[a[i]]==id) res=max(res,i-pos[a[i]]);
			else {
				last[a[i]]=id;
				pos[a[i]]=i;
			}
		}
		cout<<res<<'\n';
	}
}