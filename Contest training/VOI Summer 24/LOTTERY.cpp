#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,a,b,res;
int p[N+5];
int cnt[N+5];
void calc(int x,int c) {
	int temp=a/x*x;
	if (temp<a) temp+=x; 
	for (int i=temp;i<=b;i+=x) cnt[i-a]+=c;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>p[i];
	cin>>a>>b;
	sort(p+1,p+1+n);
	int cur=1;
	for (int i=1;i<=n;i++) {
		if (p[i]!=p[i+1]) {
			calc(p[i],cur);
			cur=1;
		} else cur++;
	}
	for (int i=a;i<=b;i++) res+=(cnt[i-a]==k);
	cout<<res;
}
