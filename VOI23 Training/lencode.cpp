#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s,t;
vector<pair<string,char>>vs,vt,v;
vector<int>pos;
int z[N+5];
bool smaller(string a,string b) {
	if (a.size()!=b.size()) return a.size()<b.size();
	for (int i=0;i<(int)a.size();i++) {
		if (a[i]!=b[i]) return a[i]<b[i];
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>t;
    string cur;
    for (int i=0;i<(int)t.size();i++) {
    	if (t[i]>='0'&&t[i]<='9') cur+=t[i];
    	else {
    		if (i==0) vt.push_back({"1",t[i]});
    		else if (t[i-1]>='a'&&t[i-1]<='z') vt.push_back({"1",t[i]});
    		else {
    			vt.push_back({cur,t[i]});
    			cur.clear();
    		}
    	}
    }
    int m=vt.size();
    if (m==1) {
    	for (auto c:s) {
    		if (c==vt.back().second) {
    			cout<<"YES";
    			return 0;
    		}
    	}
		cout<<"NO";
		return 0;
    }
    for (int i=1;i<m-1;i++) v.push_back(vt[i]);
    v.push_back({"0",'#'});
    cur.clear();
    for (int i=0;i<(int)s.size();i++) {
    	if (s[i]>='0'&&s[i]<='9') cur+=s[i];
    	else {
    		if (i==0) vs.push_back({"1",s[i]});
    		else if (s[i-1]>='a'&&s[i-1]<='z') vs.push_back({"1",s[i]});
    		else {
    			vs.push_back({cur,s[i]});
    			cur.clear();
    		}
    	}
    }
    for (auto p:vs) v.push_back(p);
    int n=v.size();
    for (int i=1,l=0,r=0;i<n;i++) {
    	if (i<=r) z[i]=min(r-i+1,z[i-l]);
    	while (i+z[i]<n&&v[z[i]]==v[i+z[i]]) z[i]++;
    	if (i+z[i]-1>r) {
    		l=i;
    		r=i+z[i]-1;
    	}
    }
    for (int i=m-1;i<n;i++) 
    	if (z[i]==m-2) pos.push_back(i-m+1);
    pair<string,char>fi=vt[0],lst=vt.back();
    for (auto p:pos) {
    	if (p==0||p-2+m>=(int)vs.size()) continue;
    	if (vs[p-1].second==fi.second&&smaller(fi.first,vs[p-1].first)&&vs[p-2+m].second==lst.second&&smaller(lst.first,vs[p-2+m].first)) {
    		cout<<"YES";
    		return 0;
    	}
    }
    cout<<"NO";
}