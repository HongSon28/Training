#include<bits/stdc++.h>
using namespace std;
string sb,se,t1,t2;
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>sb>>se;
	int r=sb.size()-1,l=0;
	while (r>=0&&l<(int)se.size()) {
		t1=sb[r]+t1;
		t2+=se[l];
		if (t1==t2) res=l+1;
		r--;
		l++;
	}
	cout<<sb.size()+se.size()-res;
}