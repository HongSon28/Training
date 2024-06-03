#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int r1,r2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	bool par=false;
	int cur=0;
	for (int i=1;i<=n;i++) {
		if (s[i]=='_') {
			if (!par) r1=max(r1,cur);
			else if (cur!=0) r2++;
			cur=0;
		} else if (s[i]=='(') {
			r1=max(r1,cur);
			cur=0;
			par=true;
		}
		else if (s[i]==')') {
			if (cur!=0) r2++;
			cur=0;
			par=false;
		}
		else cur++;
	}
	cout<<r1<<' '<<r2;
}