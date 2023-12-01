#include<bits/stdc++.h>
using namespace std;
int n;
long long res,mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=0;i<=(n/3);i++) {
    	int left=n-(i*3);
    	res+=1+left/2;
    	res%=mod;
    }
    cout<<res;
}