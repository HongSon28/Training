#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	n%=4;
	if (n==0) cout<<3;
	else if (n==1) cout<<6;
	else if (n==2) cout<<4;
	else cout<<1;
}