#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int f(int i) {
	long long cur=i, res=0;
	while (cur<=n) {
		res++;
		cur=cur*10+i;
	}
	return res;
}
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n;
    	int res=0;
    	for (int i=1;i<=9;i++) {
    		res+=f(i);
    	}
    	cout<<res<<'\n';
    }
}
