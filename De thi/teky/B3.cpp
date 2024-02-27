#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>a>>b;
	long long res=n/b;
	long long cur=b*res;
	while ((n-cur)%a!=0) {
		cur-=b;
		res--;
	}
	res+=(n-cur)/a;
	cout<<res;
}