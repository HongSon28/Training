#include<bits/stdc++.h>
using namespace std;
const int N=40;
int n,m;
set<int>s;
int a[N+5];
int res;
void rec1(int k,int sum) {
	if (k==n/2+1) {
		s.insert(sum);
		res=max(res,sum);
		return;
	}
	rec1(k+1,(sum+a[k])%m);
	rec1(k+1,sum);
}
int get(int v) {
	auto it=s.lower_bound(m-v);
	if (it==s.begin()) return v;
	it--;
	return (*it)+v;
}
void rec2(int k,int sum) {
	if (k==n+1) {
		res=max(res,get(sum));
		return;
	}
	rec2(k+1,(sum+a[k])%m);
	rec2(k+1,sum);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	a[i]%=m;
    }	
    rec1(1,0);
    rec2(n/2+1,0);
    cout<<res;
}