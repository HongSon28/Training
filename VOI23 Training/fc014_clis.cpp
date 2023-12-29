#include<bits/stdc++.h>
using namespace std;
const int N=200;
string s;
vector<int>v(N+5,INT_MAX);
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    v[0]=INT_MIN;
    cin>>s;
    for (auto i:s) {
    	int k=upper_bound(v.begin(),v.end(),i-'A')-v.begin();
    	res=max(res,k);
    	v[k]=i-'A';
    }
    cout<<res;
}