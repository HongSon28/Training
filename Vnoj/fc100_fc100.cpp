#include<bits/stdc++.h>
using namespace std;
string s,t="Free Contest 100";
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (true) {
    	getline(cin,s);
    	if (s==t) {
    		cout<<"Let's start!";
    		return 0;
    	} else cout<<"Wait"<<'\n';
    }
}