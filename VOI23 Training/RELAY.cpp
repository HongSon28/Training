#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k;
struct dat{
	int a,b,c;
	bool operator < (const dat &other) const {
		if (a!=other.a) return a<other.a;
		return b<other.b;
	}
} a[N+5];
vector<int>cprs;
int main() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i].a>>a[i].b>>a[i].c;
		cprs.push_back(a[i].a);
		cprs.push_back(a[i].b);
	}
	cprs.push_back(k);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) {
		a[i].a=lower_bound(cprs.begin(),cprs.end(),a[i].a);
		a[i].b=lower_bound(cprs.begin(),cprs.end(),a[i].b);
	}
	sort(a+1,a+1+n);
	k=lower_bound(cprs.begin(),cprs.end(),k);
	for (int i=1;i<=n;i++) {
		
	}
}