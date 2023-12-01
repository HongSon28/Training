#include<bits/stdc++.h>
using namespace std;
int q;
long long ax,ay,bx,by;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>q;
	while (q--) {
		cin>>ax>>bx>>ay>>by;
		if (bx>by) {
			bx-=by;
			by=0;
		} else if (bx<by) {
			by-=bx;
			bx=0;
		} else {
			bx=0;
			by=0;
		}
		if (ax>0) {
			while (bx--) ax*=10;
		}
		if (ay>0) {
			while (by--) ay*=10;
		}
		if (ax<ay) cout<<"X < Y"<<'\n';
		else if (ax==ay) cout<<"X = Y"<<'\n';
		else cout<<"X > Y"<<'\n';
	}
}