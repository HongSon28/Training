#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	x=n/7,y=n%7;
	cout<<x*2+max(0,y-5)<<' '<<x*2+min(2,y);
}