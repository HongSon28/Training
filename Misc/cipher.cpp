#include<bits/stdc++.h>
using namespace std;
int k;
string s;
int main() {	
	freopen("ciphertext.inp","r",stdin);
    freopen("plaintext.out","w",stdout);
    cin>>k>>s;
    for (int i=0;i<s.size();i++) {
    	if (s[i]>=65&&s[i]<=90) {
    		s[i]-=k;
    		if (s[i]<65) s[i]+=26;
    	} else {
    		s[i]-=k;
    		if (s[i]<97) s[i]+=26;
    	}
    }
    cout<<s;
}