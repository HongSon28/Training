#include<bits/stdc++.h>
using namespace std;
string s;
int n,res=0;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>s;
    s+=' ';
    int cur=1;
    for (int i=1;i<=n;i++) {
    	if (s[i]==s[i-1]) cur++;
    	else {
    		res+=cur/2;
    		cur=1;
    	}
    }
    cout<<res;
}