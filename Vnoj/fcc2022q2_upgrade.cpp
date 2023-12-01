#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,res;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    res=n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    }
    if (k==1) {
    	cout<<res;
    	return 0;
    }
    sort(a+1,a+1+n);
    int cur=0;
    for (int i=1;i<=n;i++) {
    	if (a[i]==a[i+1]) cur++;
    	else {
    		cur++;
    		//cout<<cur<<' ';
    		while (cur>=k) {
    			res-=cur;
    			int temp=cur/k;
    			res+=cur%k+temp;
    			cur=temp;
    			a[i]++;
    			if (a[i]==a[i+1]) break;
    		}
    		//cout<<res<<' '<<cur<<endl;
    		if (a[i]!=a[i+1]) cur=0;
    	}
    }
    cout<<res;
}