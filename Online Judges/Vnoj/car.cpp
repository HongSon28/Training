#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
long long res,cur;
struct dat{
	long long a,b,id;
	bool operator < (const dat &other) const {
		double x=(double)a/(double)b;
		double y=(double)other.a/(double)other.b;
		return x>y;
	}
} a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].a;
	for (int i=1;i<=n;i++) {
		cin>>a[i].b;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		cur+=a[i].b;
		res+=cur*a[i].a;
	}
	cout<<res<<'\n';
	for (int i=1;i<=n;i++) cout<<a[i].id<<' ';
}