#include<bits/stdc++.h>
using namespace std;
int t;
char x;
int y;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>x>>y;
    	for (int i=1;i<y;i++) cout<<x<<i<<'\n';
    	for (int i=y+1;i<=8;i++) cout<<x<<i<<'\n';
    	for (char c='a';c<x;c++) cout<<c<<y<<'\n';
    	for (char c='h';c>x;c--) cout<<c<<y<<'\n';
    }
}