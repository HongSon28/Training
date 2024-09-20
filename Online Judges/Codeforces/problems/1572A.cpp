#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
vector<int>v[N+5];
set<int>s;
int lft[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	int k,a,res=1;
    	cin>>n;
    	s.clear();
    	for (int i=1;i<=n;i++) 
    		v[i].clear();
    	for (int i=1;i<=n;i++) {
    		cin>>k;
    		lft[i]=k;
    		if (k==0) s.insert(i);
	    	while (k--) {
	    		cin>>a;
	    		v[a].push_back(i);
	    	}
    	}
    	queue<int>q;
    	int last=0,cnt=n;
    	while (cnt>0) {
    		if (s.empty()&&q.empty()) {
    			res=-1;
    			break;
    		}
    		if (s.empty()) {
    			while (!q.empty()) {
    				s.insert(q.front());
    				q.pop();
    			}
    			last=0;
    			res++;
    		} else {
    			int u=*s.begin();
    			s.erase(s.begin());
    			cnt--;
    			for (auto t:v[u]) {
    				lft[t]--;
    				if (!lft[t]) {
    					if (t>u) s.insert(t);
    					else q.push(t);
    				}
    			}
    		}
    	}
    	cout<<res<<'\n';
    }
}