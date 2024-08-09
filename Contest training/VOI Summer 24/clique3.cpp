#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n;
int a[N+5];
int c[N+5];
int l[N+5],r[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	c[a[i]]++;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
    	if (a[i]==a[i-1]) continue;
    	for (int j=a[i]*2;j<=N;j+=a[i]) {
    		l[j]+=c[a[i]];
    		r[a[i]]+=c[j];
    	}
    }
    for (int i=1;i<=n;i++) {
    	if (a[i]==a[i-1]) continue;
    	long long temp=c[a[i]]*(c[a[i]]-1)*(c[a[i]]-2)/6;
    	temp+=c[a[i]]*l[a[i]]*r[a[i]];
    	//cout<<c[a[i]]<<' '<<l[a[i]]<<' '<<r[a[i]]<<endl;
    	res+=temp;
    }
    cout<<res;
}