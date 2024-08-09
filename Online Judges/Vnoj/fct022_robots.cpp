#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
struct seg{
	int l,r;
	bool operator < (const seg &other) const{
		return r<other.r;
	}
}a[N+5]; 
int res,cur=INT_MIN;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		int x,l;
		cin>>x>>l;
		a[i]={x-l,x+l};
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		if (a[i].l>=cur) {
			cur=a[i].r;
			res++;
		}
	}
	cout<<res;
}