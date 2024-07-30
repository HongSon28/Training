#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m,c1,c2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>s>>m>>t;
    s+=s;
	s+=s;
    s=' '+s;
    for (auto i:t) {
    	if (i=='1') c1++;
    	else c2++;
    }
    c1%=10;
    c2%=n;
    for (int i=n-c2+1;i<=n+n-c2;i++) {
    	int temp=s[i]-'0';
    	temp+=c1;
    	temp%=10;
    	cout<<temp;
    }
}