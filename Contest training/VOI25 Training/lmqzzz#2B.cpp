#include<bits/stdc++.h>
using namespace std;
const int N=1500;
int n;
pair<long long,long long>a[N+5];
long long res;
struct line {
	pair<long long,long long>x,y,mid;
	long long d;
	bool operator < (const line &other) const {
		if (mid!=other.mid) return mid<other.mid;
		return d<other.d;
	}
};
vector<line>v;
vector<line>vc;
long long dist(pair<long long,long long>x,pair<long long,long long>y) {
	return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void calc() {
	for (int i=0;i<(int)vc.size()-1;i++) {
		for (int j=i+1;j<(int)vc.size();j++) {
			double d1=dist(vc[i].x,vc[j].x);
			double d2=dist(vc[i].y,vc[j].x);
			d1=sqrt(d1),d2=sqrt(d2);
			double temp=d1*d2;
			res=max(res,(long long)temp);
		}
	}
	vc.clear();
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for (int i=1;i<=n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		pair<long long,long long>mid=make_pair(a[i].first+a[j].first,a[i].second+a[j].second);
    		long long d=dist(a[i],a[j]);
    		v.push_back({a[i],a[j],mid,d});
    	}
    }
    sort(v.begin(),v.end());
    vc.push_back(v[0]);
    for (int i=1;i<(int)v.size();i++) {
    	if (v[i].mid!=v[i-1].mid||v[i].d!=v[i-1].d) calc();
    	vc.push_back(v[i]);
    }
    calc();
    cout<<res;
}