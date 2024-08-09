#include<bits/stdc++.h>
using namespace std;
int t;
long long k,x,a;
long long get_next(long long t) {
	return t/(k-1)+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		bool flag=true;
		cin>>k>>x>>a;
		long long sum=0;
		for (int i=1;i<=x;i++) {
			long long cur=get_next(sum);
			if (cur>a-sum) {
				flag=false;
				break;
			}
			sum+=cur;
		}
		if (flag) {
			if ((a-sum)*k>a) cout<<"YES";
			else cout<<"NO";
		} else cout<<"NO";
		cout<<'\n';
	}
}