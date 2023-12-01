#include<bits/stdc++.h>
using namespace std;
const int N=3e4;
int t,n;
string s;
long long MOD=1e9+7;
long long power[N+5],hashh[N+5];
long long base=311;
void prep() {
	power[0] = 1;
    for (int i=1;i<=N;i++)
        power[i]=(power[i-1]*base)%MOD;
}
void create_hash(){
    for (int i=1;i<s.size();i++)
        hashh[i]=(hashh[i-1]*base+(int)s[i])%MOD;
}
long long get_hash(int l, int r) {
    return (hashh[r]-hashh[l-1]*power[r-l+1]+MOD*MOD)%MOD;
}
int main() {
	prep();
	cin>>t;
	while (t--) {
		cin>>s;
		n=s.size();
		create_hash();
		
	}
}
