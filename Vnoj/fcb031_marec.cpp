#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int cnt,res,n,t;
int c[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>t;
    	c[t]++;
    	if (c[t]==2) cnt++;
    	if (c[t]==4) res++;
    }
    cout<<res+(cnt-1)*cnt/2;
}