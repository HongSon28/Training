#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k,a[N+5],res;
priority_queue<long long>pq;
int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) a[i]-=k*(i-1);
	for (int i=1;i<=n;i++) {
		pq.push(a[i]);
		if (a[i]<pq.top()) {
			res+=pq.top()-a[i];
			pq.pop();
			pq.push(a[i]);
		}
	}
	cout<<res;
}