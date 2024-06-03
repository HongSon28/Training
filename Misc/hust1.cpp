#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	cout.precision(4);
	for (int i=1;i<=n;i++) cout<<fixed<<(double)i*i<<' ';
	cout<<endl;
	for (int i=n+1;i<=n*2;i++) {
		double t=sqrt(i);
		cout<<fixed<<t<<' ';
	}
}