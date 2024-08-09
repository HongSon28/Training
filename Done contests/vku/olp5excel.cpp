#include<bits/stdc++.h>
using namespace std;
int m,n,q;
int a[10][27];
struct dat{
	int type,cnt,val;
};
stack<dat>st;
void solve(string s) {
	while (!st.empty()) st.pop();
	int i=0;
	while (i<(int)s.size()) {
		if (i+3<(int)s.size()) {
			string t=s.substr(i,4);
			if (t=="SUM(") {
				st.push({1,0,0});
				i+=4;
				continue;
			} else if (t=="MAX(") {
				st.push({2,0,0});
				i+=4;
				continue;
			}
		} 
		if (i+1<(int)s.size()) {
			string t=s.substr(i,2);
			if (t[0]>='A'&&t[0]<='Z'&&t[1]>='1'&&t[1]<='9') {
				int x=t[1]-'1'+1;
				int y=t[0]-'A'+1;
				st.push({3,0,a[x][y]});
				i+=2;
			}
		}
		if (s[i]==','||s[i]==')') i++;
		while (st.size()>=2&&st.top().type==3) {
			int t=st.top().val;
			st.pop();
			dat d=st.top();
			st.pop();
			if (d.type==1) d.val+=t;
			else d.val=max(d.val,t);
			d.cnt++;
			if (d.cnt==2) st.push({3,0,d.val});
			else st.push(d);
		}
	}
	cout<<st.top().val<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>m>>n;
	for (int i=1;i<=m;i++) 
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	cin>>q;
	while (q--) {
		string s;
		cin>>s;
		solve(s);
	}
}