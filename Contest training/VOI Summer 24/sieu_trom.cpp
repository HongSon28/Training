#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n;
long long m;
long long w[N+5],v[N+5],res;
void rec(int k,long long x,long long y) {
	if (k==n+1) {
		res=max(res,y);
		return;
	}
	rec(k+1,x,y);
	if (x+w[k]<=m) rec(k+1,x+w[k],y+v[k]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
    rec(1,0,0);
    cout<<res;	
}