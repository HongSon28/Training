#include<bits/stdc++.h>
using namespace std;
string s;
long long res,cur;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    for (auto i:s) {
    	if (i=='1') cur++;
    	else if (i=='2') res+=cur;
    }
    cout<<res;
}