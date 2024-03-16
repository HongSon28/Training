#include<bits/stdc++.h>
using namespace std;
int n,a,res;
bool check(int x) {
	int last=x%10;
	x/=10;
	while (x>0) {
		if (last!=x%10) return false;
		x/=10;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a;
		if (check(a)) res++;
	}
	cout<<res;
}