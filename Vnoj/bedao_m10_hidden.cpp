#include<bits/stdc++.h>
using namespace std;
long long a,t,cnt,x=1,y=1;
long long power(long long x,long long y) {
	long long ans=1;
	for (int i=1;i<=y;i++) ans*=x;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>a>>t;
	if (t%a!=0) {
		cout<<-1;
		return 0;
	}
	for (long long i=2;i*i<=t;i++) {
		if (t%i!=0) continue;
		int cur=0;
		while (t%i==0) {
			t/=i;
			cur++;
		}
		if (cnt==0) x=power(i,cur);
		else y*=power(i,cur);
		cnt++;
	}
	if (t!=1) y*=t;
	if (x==1||y==1) cout<<-1;
	else cout<<x<<' '<<y;
}