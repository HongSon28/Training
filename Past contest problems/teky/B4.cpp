#include<bits/stdc++.h>
using namespace std;
long long n,k,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;	
    while (n>0) {
    	n-=k;
    	k*=2;
    	res++;
    }
    cout<<res;
}