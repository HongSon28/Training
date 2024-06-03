#include<bits/stdc++.h>
using namespace std;
int n,x;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    while (n--) {
    	string t;
    	cin>>t;
    	if (t[1]=='+') x++;
    	else x--;
    }
    cout<<x;
}