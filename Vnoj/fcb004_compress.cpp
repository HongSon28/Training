#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(int k) {
	string t=s.substr(1,k);
	string str=" ";
	for (int i=1;i<=n/k;i++) str+=t;
	return (str==s);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;i++) {
    	if (n%i!=0) continue;
    	if (check(i)) {
    		cout<<n/i<<s.substr(1,i);
    		return 0;
    	}
    }
}