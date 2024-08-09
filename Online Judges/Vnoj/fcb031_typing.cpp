#include<bits/stdc++.h>
using namespace std;
string s;
long long res=1,mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    s+=' ';
    int cur=1;
    for (int i=0;i<(int)s.size()-1;i++) {
    	if (s[i]!=s[i+1]) {
    		res*=cur;
    		res%=mod;
    		cur=1;
    	} else cur++;
    }
    cout<<res;
}