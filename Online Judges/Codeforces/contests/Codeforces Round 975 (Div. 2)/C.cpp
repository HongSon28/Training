#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long k;
long long a[N+5],num,sum,lim=1e8;
bool check(long long num,long long sz) {
	long long temp=(sum+k)%num;
	long long cur=sum+k-temp;
	return (cur>=sum);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k;
		num=0,sum=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			num=max(num,a[i]);
			sum+=a[i];
		}
		long long sz=(sum+num-1)/num;
		while (true) {
			//cout<<num<<' '<<sz<<endl;
			if (check(num,sz)) {
				sz=(sum+k)/num;
				cout<<min(sz,(long long)n)<<'\n';
				break;
			}
			if (num<lim) {
				num++;
				sz=(sum+num-1)/num;
			} else {
				sz--;
				num=(sum+k)/sz;
			}
		}
	}
}