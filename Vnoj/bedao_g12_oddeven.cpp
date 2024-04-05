#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long res;
int a[N+5];
int c1,c2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		c1+=(a[i]%2==0);
	}
	c2=n-c1;
	if (c1!=(n/2)||c2!=(n+1)/2) {
		cout<<-1;
		return false;
	}
	int cur=1;
	for (int i=1;i<=n;i++) {
		if (a[i]%2==0) {
			res+=abs(i-cur*2);
			cur++;
		}
	}
	cout<<res;
}