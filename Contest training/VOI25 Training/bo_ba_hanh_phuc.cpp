#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int p[N+5];
long long res,cnt[N+5];
void seive() {
	for (int i=1;i<=N;i++) p[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (p[i]==i) for (int j=i*i;j<=N;j+=i) if (p[j]>i) p[j]=i;
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
    	int temp=1;
    	while (a[i]>1) {
    		int div=p[a[i]],cnt=0;
    		while (a[i]%div==0) {
    			a[i]/=div;
    			cnt++;
    		}
    		if (cnt&1) temp*=div;
    	}
    	cnt[temp]++;
    }	
    int t[4];
    for (int i=1;i<=N;i++) {
    	for (int j=1;j<=min(i,N/i);j++) {
    		for (int k=1;k<=j;k++) {
    			t[1]=i*j,t[2]=j*k,t[3]=k*i;
    			sort(t+1,t+4);
    			if (t[1]==t[3]) res+=cnt[t[1]]*(cnt[t[1]]-1)*(cnt[t[1]]-2)/6;
    			else if (t[1]==t[2]) res+=cnt[t[1]]*(cnt[t[1]]-1)/2*cnt[t[3]];
    			else if (t[2]==t[3]) res+=cnt[t[1]]*cnt[t[2]]*(cnt[t[2]]-1)/2;
    			else res+=cnt[t[1]]*cnt[t[2]]*cnt[t[3]];
    		}
    	}
    }
    cout<<res;
}