#include<bits/stdc++.h>
using namespace std;
int n;
long long res;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	while (n--) {
		cin>>s;
		for (auto i:s) {
			if (i=='A') res+=4;
			else if (i=='K') res+=3;
			else if (i=='Q') res+=2;
			else if (i=='J') res++;
		} 
	}
	cout<<res;
}