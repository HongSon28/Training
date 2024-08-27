#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) 
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    int n;
    while (cin>>n) {
    	cout<<1;
    	while (n>1) {
    		cout<<" x "<<d[n];
    		n/=d[n];
    	}
    	cout<<'\n';
    }
}