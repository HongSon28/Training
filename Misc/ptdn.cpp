#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N+5];
long long res;
bool p[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=1;
	while (r<=n) {
		while (p[a[r]]) {
			p[a[l]]=false;
			l++;
		}
		p[a[r]]=true;
		res+=r-l+1;
		r++;
	}
	cout<<res;
}