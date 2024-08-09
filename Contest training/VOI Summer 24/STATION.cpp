#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=3e3;
int n;
bitset<N>s[N];
long long res;
int calc(int x) {
	return x*(x-1);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++) cin>>s[i];
    for (int i=0;i<n;i++) {
    	for (int j=i+1;j<n;j++) {
    		res+=calc((s[i]&s[j]).count());
    	}
    }
    cout<<(res>>1);
}