#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5];
bool used[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	long long res=0;
    	int g=0;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		used[i]=false;
    		g=__gcd(g,a[i]);
    	}
    	for (int i=1;i<=n;i++) a[i]/=g;
    	sort(a+1,a+1+n);
    	used[1]=true;
    	res=a[1];
    	int cur=a[1];
    	for (int i=2;i<=n;i++) {
    		int mn=cur,pos=0;
    		for (int i=1;i<=n;i++) {
    			if (used[i]) continue;
    			int temp=__gcd(cur,a[i]);
    			if (temp<mn) {
    				mn=temp;
    				pos=i;
    			}
    		}
    		used[pos]=true;
    		cur=mn;
    		res+=cur;
    		if (cur==1) {
    			res+=n-i;
    			break;
    		}
    	}
    	cout<<res*g<<'\n';
    }
}