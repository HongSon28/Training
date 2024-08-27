#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a,b;
bool p[N+5];
void seive() {
	memset(p,true,sizeof(p));
	p[0]=p[1]=false;
	for (int i=4;i<=N;i+=2) p[i]=false;
	for (int i=3;i*i<=N;i+=2) {
		if (p[i])
			for (int j=i*i;j<=N;j+=i) p[j]=false;
	}
	for (int i=a;i<=b;i++) 
		if (p[i]) cout<<i<<'\n'; 
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b;
    seive();
}