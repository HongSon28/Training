#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
vector<int>v;
void calc() {
	vector<int>cur;
	int a[3];
	for (int i=1;i+1<(int)v.size();i++) {
		a[0]=v[i-1];
		a[1]=v[i];
		a[2]=v[i+1];
		sort(a,a+3);
		cur.push_back(a[1]);
	}
	v=cur;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	v.clear();
		cin>>n;
		for (int i=1;i<=2*n-1;i++) {
			int x;
			cin>>x;
			v.push_back(x);
		}
		for (int i=1;i<n;i++) calc();
		cout<<v[0]<<'\n';
	}
}