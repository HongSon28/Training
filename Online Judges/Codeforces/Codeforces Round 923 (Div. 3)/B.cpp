#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
queue<char>q[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0;i<=n;i++) {
			while (!q[i].empty()) q[i].pop();
		}
		for (char c='a';c<='z';c++) q[0].push(c);
		for (int i=1;i<=n;i++) {
			int a;
			cin>>a;
			cout<<q[a].front();
			q[a+1].push(q[a].front());
			q[a].pop();
		}
		cout<<'\n';
	}
}