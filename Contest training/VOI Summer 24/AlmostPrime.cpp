#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int p[N+5];
void seive() {
	for (int i=2;i<=N;i++) {
		if (!p[i]) {
			for (int j=i*2;j<=N;j+=i) p[j]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    int n,res=0;
    cin>>n;
    for (int i=1;i<=n;i++) res+=(p[i]==2);
    cout<<res;
}