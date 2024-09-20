#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>s;
    	deque<pair<char,int>>st1,st2;
    	for (int i=0;i<s.size();i++) {
    		if (s[i]=='b') {
    			if (!st1.empty()) st1.pop_back();
    			continue;
    		}
    		if (s[i]=='B') {
    			if (!st2.empty()) st2.pop_back();
    			continue;
    		}
    		if (s[i]>='a'&&s[i]<='z') st1.push_back({s[i],i});
    		else st2.push_back({s[i],i});
    	}
    	while (!st1.empty()||!st2.empty()) {
    		if (st1.empty()) {
    			cout<<st2.front().first;
    			st2.pop_front();
    		} else if (st2.empty()) {
    			cout<<st1.front().first;
    			st1.pop_front();
    		} else {
    			if (st1.front().second<st2.front().second) {
    				cout<<st1.front().first;
    				st1.pop_front();
    			} else {
    				cout<<st2.front().first;
    				st2.pop_front();
    			}
    		}
    	}
    	cout<<'\n';
    }
}