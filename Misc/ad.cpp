#include<bits/stdc++.h>
using namespace std;
int n,D;
int v[11],d[11];
bool c[11][11];
int mx_val, mx_l=1e9;
int a[11],res[11],cur,m;
bool check(int i) {
	for (int j=1;j<=cur;j++) {
		if (c[i][a[j]]) return false;
	}
	return true;
}
void rec(int i,int val,int l) {
	if (i==n+1) {
		if (val>mx_val) {
			mx_val=val;
			mx_l=l;
			m=cur;
			for (int j=1;j<=m;j++) res[j]=a[j];
		} else if (val==mx_val) {
			if (l<mx_l) {
				mx_l=l;
				m=cur;
				for (int j=1;j<=m;j++) res[j]=a[j];
			}
		}
		return;
	}
	rec(i+1,val,l);
	if (l+d[i]<=D&&check(i)) {
		cur++;
		a[cur]=i;
		rec(i+1,val+v[i],l+d[i]);
		cur--;
	} 
}
int main() {
	freopen("brand.txt","r",stdin);
    freopen("maximum_profit.txt","w",stdout);
    cin>>n>>D;
    for (int i=1;i<=n;i++) {
    	cin>>v[i]>>d[i];
    	int k;
    	cin>>k;
    	for (int j=1;j<=k;j++) {
    		int t;
    		cin>>t;
    		c[i][t]=c[t][i]=true;
    	}
    }
    rec(1,0,0);
    cout<<"Maximum profit: "<<mx_val<<'\n';
    cout<<"Selected brands: ";
    for (int i=1;i<=m;i++) cout<<res[i]<<' ';
}