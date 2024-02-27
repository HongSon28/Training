#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,mx;
string s;
long long c[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    int cur=0;
    for (auto i:s) {
    	if (i=='7') cur++;
    	else if (cur!=0) {
    		mx=max(mx,cur);
    		for (int j=cur;j>=1;j--) c[j]+=cur-j+1;
    		cur=0;
    	}
    }
    if (cur!=0) {
    	mx=max(mx,cur);
    	for (int i=cur;i>=1;i--) c[i]+=cur-i+1;
    }
	for (int i=1;i<=mx;i++) cout<<i<<' '<<c[i]<<'\n';
}