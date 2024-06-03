#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt[27];
int main() {
    cin>>n;
    while (n--) {
    	memset(cnt,0,sizeof(cnt));
    	cin>>s;
    	for (auto i:s) cnt[i-'A']++;
		for (char c='A';c<='Z';c++) if (cnt[c-'A']==2) cout<<c;
    }
}