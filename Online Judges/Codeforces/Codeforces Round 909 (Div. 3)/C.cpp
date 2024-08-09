#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		int res=INT_MIN;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			res=max(res,a[i]);
		}
		int cur=0,len=0;
		for (int i=1;i<=n;i++) {
			cur+=a[i];
			len++;
			//cout<<cur<<' '<<res<<endl;
			if (cur<0) {
				cur=0;
				len=0;
				continue;	
			}
			int t1=abs(a[i]%2);
			int t2=abs(a[i-1]%2);
			if (len>1&&t1==t2) {
				len=1;
				cur=a[i];
				if (cur<0) {
					cur=0;
					len=0;
				}
				continue;
			}	 
			res=max(res,cur);
		}
		cout<<res<<'\n';
	}
}