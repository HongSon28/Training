#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n;
int a[N+5],cnt[N+5];
int d[N+5];
long long res,c[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) {
			for (int j=i*i;j<=N;j+=i) 
				if (d[j]>i) d[j]=i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cnt[a[i]]++;
    }
    for (int i=2;i<=N;i++) {
    	for (int j=i;j<=N;j+=i) c[i]+=cnt[j];
    }
    res=(long long)n*(n-1)/2;
    for (int i=2;i<=N;i++) {
    	int cnt=0;
    	int j=i;
    	bool flag=true;
    	while (j>1) {
    		cnt++;
    		int t=0;
    		int cur=d[j];
    		while (j%cur==0) {
    			j/=cur;
    			t++;
    		}
    		if (t>1) {
    			flag=false;
    			break;
    		}
    	}
    	if (!flag) continue;
    	long long cur=c[i]*(c[i]-1)/2;
    	if (cnt%2==1) res-=cur;
    	else res+=cur;
    	//cout<<i<<' '<<cnt<<' '<<cur<<endl;
    }
    cout<<res;
}