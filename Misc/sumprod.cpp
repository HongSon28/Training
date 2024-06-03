#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		if (n<=9) for (int i=1;i<=n;i++) cout<<n;
		else if(n==10) cout<<1234567893;
		else {
			int x=__lg(n),y=x+1;
			if (abs(n-(1<<x))<=abs(n-(1<<y))) {
				int dif=n-(1<<x);
				for (int i=1;i<=n-dif*2;i++) cout<<2;
				for (int i=1;i<=dif*2;i++) cout<<1;
			} else {
				int dif=(1<<y)-n;
				for (int i=1;i<=n-dif;i++) cout<<2;
				for (int i=1;i<=dif;i++) cout<<4;
			}
		}
		cout<<'\n';
	}
}
