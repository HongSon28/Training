#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5],l[N+5],r[N+5],p[N+5],q[N+5];
long long res;
stack<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	while (!st.empty()&&a[i]>a[st.top()]) {
    		r[st.top()]=i;
    		st.pop();
    	}
    	st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
    	while (!st.empty()&&a[i]>a[st.top()]) {
    		l[st.top()]=i;
    		st.pop();
    	}
    	st.push(i);
    }
    p[1]=a[1];
    for (int i=2;i<=n;i++) p[i]=max(p[i-1],a[i]);
    q[n]=a[n];
    for (int i=n-1;i>=1;i--) q[i]=max(q[i+1],a[i]);
    for (int i=1;i<=n;i++) res+=min(p[i],q[i])-a[i];
    long long sum=res;
    for (int i=1;i<=n;i++) {
    	if (a[i]<p[i]&&a[i]<q[i]) continue;
    	if (a[i]>=p[i]&&a[i]>=q[i]) continue;
    	long long temp=sum;
    	if (a[i]<p[i]) temp+=i-l[i]-1;
    	if (a[i]<q[i]) temp+=r[i]-i-1;
    	res=max(res,temp);
    }
    cout<<res;
}