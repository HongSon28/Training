#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N+5];
int n,m;
pair<int,pair<int,int>>p[N*N+5];
int bs(pair<int,pair<int,int>>x) {
	int l=1,r=m;
	while (l<=r) {
		int mid=(l+r)/2;
		if (p[mid]>=x) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	return l;
}
int main() {
    freopen("TBC.INP","r",stdin);
    freopen("TBC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int res=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            p[++m]={a[i]+a[j],{i,j}};
    sort(p+1,p+1+m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            pair<int,pair<int,int>>temp={3*a[i]-a[j],{j+1,0}};
            int l=bs(temp);
            if (p[l].first==temp.first) {
                res++;
                break;
            }
        }
    }
    cout<<res;
}
