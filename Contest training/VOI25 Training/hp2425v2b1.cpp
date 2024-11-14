#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=1e8;
int s,t;
bool p[N+1];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	for (int i=1;i*i<=s;i++) {
		t=i*i;
		for (int j=0;t+j*j<=s&&j<=i;j++) p[t+j*j]=true;
	}
	for (int i=0;i<=s;i++) res+=p[i];
	cout<<res;
}