#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	cout<<v[k-1];
}