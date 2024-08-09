#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
int mx,mn=INT_MAX,sum;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		char c;
		cin>>c;
		if (c=='1') a[i]=1,sum++;
		else a[i]=-1;
	}
	int cur=0;
	for (int i=1;i<=n;i++) {
		cur+=a[i];
		if (cur<0) cur=0;
		mx=max(mx,cur);
	}
	cur=0;
	for (int i=1;i<=n;i++) {
		cur+=a[i];
		if (cur>0) cur=0;
		mn=min(mn,cur);
	}
	cout<<mx-mn+1;
}