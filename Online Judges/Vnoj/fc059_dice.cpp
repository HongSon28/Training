#include<bits/stdc++.h>
using namespace std;
long long n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	long long t=n%6;
	if (t==0) cout<<n/6;
	else cout<<n/6+7-t;
	cout<<' '<<n*6;
}