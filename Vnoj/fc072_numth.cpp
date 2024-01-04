#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int k;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k;
	int x;
	while (cin>>x) {
		v.push_back(x);
	}
	sort(v.rbegin(),v.rend());
	cout<<v[k-1];
}