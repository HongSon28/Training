#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
int x[N+5],y[N+5],cx[N+5],cy[N+5];
stack<int>st;
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>x[i];
    	cx[i]=x[i];
    }
    for (int i=1;i<=n;i++) {
    	cin>>y[i];
    	cy[i]=y[i];
    }
    st.push(1);
    for (int i=2;i<=n;i++) {
    	while (!st.empty()) {
    		int u=st.top();
    		int temp=min(cx[u],cy[i]);
    		cx[u]-=temp;
    		cy[i]-=temp;
    		res+=temp;
    		if (cx[u]==0) st.pop();
    		else break;
    	}
    	st.push(i);
    }
    for (int i=1;i<=n;i++) {
    	int temp=min(cx[i],cy[i]);
    	cx[i]-=temp,cy[i]-=temp;
    	res-=cy[i];
    }
    cout<<res;
}