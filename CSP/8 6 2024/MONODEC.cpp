#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void rec(int k,int last,int sum) {
	if (k==10) return;
	for (int i=last+1;i<=9;i++) {
		rec(k+1,i,sum*10+i);
		v.push_back(sum*10+i);
	}
}
void prep() {
	v.push_back(0);
	rec(1,0,0);
	sort(v.begin(),v.end());
}
int main() {
	freopen("MONODEC.INP","r",stdin);
    freopen("MONODEC.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    int t,a;
    cin>>t;
    while (t--) {
    	cin>>a;
    	auto i=upper_bound(v.begin(),v.end(),a);
    	i--;
    	cout<<*i<<'\n';
    }
}