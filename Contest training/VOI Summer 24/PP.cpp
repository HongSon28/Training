#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long s[N+5];
void seive() {
	for (int i=1;i<=N;i++) {
		for (int j=i*2;j<=N;j+=i) s[j]+=i;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    int l,r,res=0;
    cin>>l>>r;
    for (int i=l;i<=r;i++) res+=(s[i]>i);
    cout<<res;
}