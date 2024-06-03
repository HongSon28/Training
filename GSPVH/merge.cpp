#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,temp;
vector<string>v;
int main() {
	freopen("merge.inp","r",stdin);
	freopen("merge.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
    	v.clear();
    	while (true) {
    		cin>>s;
    		if (s[0]>='1'&&s[0]<='9') {
    			cout<<v[stoi(s)-1]<<' ';
    			break;
    		} else v.push_back(s);
    	}
    }	
}