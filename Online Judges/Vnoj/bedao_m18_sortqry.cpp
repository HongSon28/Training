#include<bits/stdc++.h>
using namespace std;
int q,pos;
vector<int>v;
multiset<int>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    while (q--) {
    	int type,x;
    	cin>>type;
    	if (type==1) {
    		cin>>x;
    		v.push_back(x);
    	} else if (type==2) {
    		if (s.empty()) {
    			cout<<v[pos]<<'\n';
    			pos++;
    		} else {
    			cout<<*s.begin()<<'\n';
    			s.erase(s.begin());
    		}
    	} else {
    		for (int i=pos;i<(int)v.size();i++) s.insert(v[i]);
    		v.clear();
    		pos=0;
    	}
    }
}