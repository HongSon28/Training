#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,m;
int a[N+5][N+5],b[N+5][N+5];
long long h[N+5],l[N+5],c[N+5];
long long res;
long long hist() {
	stack<int>st;
	long long ans=0;
	for (int i=1;i<=m;i++) {
		while (!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if (st.empty()) l[i]=1;
		else l[i]=st.top()+1;
		st.push(i);
	}
	for (int i=1;i<=m;i++) {
		c[i]=h[i]*(i-l[i]+1)+c[l[i]-1];
		ans+=c[i];
	}
	return ans;
}
long long calc(int t,int x,int y,int z) {
	memset(h,0,sizeof(h));
	long long ans=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			b[i][j]=(a[i][j]==x);
			if (t>=2) b[i][j]|=(a[i][j]==y);
			if (t==3) b[i][j]|=(a[i][j]==z); 
			if (b[i][j]) h[j]++;
			else h[j]=0;
			//cout<<b[i][j]<<' ';	
		}
		ans+=hist();
		//cout<<endl;
	}
	//cout<<ans<<endl<<endl;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	string s;
    	cin>>s;
    	m=s.size();
    	for (int j=0;j<m;j++) {
    		a[i][j+1]=s[j]-'A'+1;
    	}
    }	
    for (int i=1;i<=3;i++) {
    	for (int j=i+1;j<=4;j++) {
    		for (int k=j+1;k<=5;k++) {
    			res+=calc(3,i,j,k);
    			res-=calc(2,i,j,0)+calc(2,i,k,0)+calc(2,j,k,0);
    			res+=calc(1,i,0,0)+calc(1,j,0,0)+calc(1,k,0,0);
    			//cout<<i<<' '<<j<<' '<<k<<' '<<res<<'\n';
    		}
    	}
    }
    cout<<res;
}