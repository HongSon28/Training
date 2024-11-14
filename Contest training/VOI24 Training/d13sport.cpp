#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=1e5;
int n;
int a[N+5],b[N+5];
bool dela[N+5],delb[N+5];
struct dat2{
	int id,col;
	bool operator < (const dat2 &other) const {
		int t1,t2;
		if (col==0) t1=a[id];
		else t1=b[id];
		if (other.col==0) t2=a[other.id];
		else t2=b[other.id];
		if (t1!=t2) return t1<t2;
		if (col!=other.col) return col<other.col;
		return id<other.id;
	}
};
set<dat2>s1;
vector<dat2>v;
struct dat{
	int d;
	int x,cx,y,cy;
	bool operator < (const dat &other) const {
		if (d!=other.d) return d<other.d;
		if (x!=other.x) return x<other.x;
		return y<other.y;
	}
};
set<dat>s2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	s1.insert({i,0});
    	v.push_back({i,0});
    }
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	s1.insert({i,1});
    	v.push_back({i,1});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<(int)v.size()-1;i++) {
    	if (v[i].col!=v[i+1].col) {
    		int t1,t2;
    		if (v[i].col==0) t1=a[v[i].id];
    		else t1=b[v[i].id];
    		if (v[i+1].col==0) t2=a[v[i+1].id];
    		else t2=b[v[i+1].id];
    		s2.insert({abs(t1-t2),v[i].id,v[i].col,v[i+1].id,v[i+1].col});
    	}
    }
    while (!s2.empty()) {
    	auto [d,x,cx,y,cy]=*s2.begin();
    	if (cx==0) {
    		if (dela[x]||delb[y]) {
    			s2.erase(s2.begin());
    			continue;
    		}
    	} else {
    		if (delb[x]||dela[y]) {
    			s2.erase(s2.begin());
    			continue;
    		}
    	}
    	if (cx==0) cout<<x<<' '<<y<<'\n';
    	else cout<<y<<' '<<x<<'\n';
    	if (cx==0) {
    		dela[x]=true;
    		delb[y]=true;
    	} else {
    		delb[x]=true;
    		dela[y]=true;
    	}
    	s2.erase(s2.begin());
    	auto it1=s1.lower_bound({x,cx});
    	auto it2=s1.lower_bound({y,cy});
    	if (it1==s1.begin()) {
    		s1.erase(it1);
    		s1.erase(it2);
    		continue;
	    }
    	auto it3=it1;
    	auto it4=it2;
    	it3--,it4++;
    	if (it4==s1.end()) {
    		s1.erase(it1);
    		s1.erase(it2);
    		continue;
    	}
    	s1.erase(it1);
    	s1.erase(it2);
    	dat2 temp1=*it3,temp2=*it4;
    	if (temp1.col!=temp2.col) {
    		int t1,t2;
    		if (temp1.col==0) t1=a[temp1.id];
    		else t1=b[temp1.id];
    		if (temp2.col==0) t2=a[temp2.id];
    		else t2=b[temp2.id];
    		s2.insert({abs(t1-t2),temp1.id,temp1.col,temp2.id,temp2.col});
    	}
    }
}
