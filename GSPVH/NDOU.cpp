#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long res;
int last[26];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    //res=n+(long long)n*(n-1)/2;
    int cur=1;
    for (int i=1;i<=n;i++) {
    	cur=max(cur,last[s[i]-'a']+1);
    	last[s[i]-'a']=i;
    	res+=i-cur+1;
    	//cout<<cur<<' '<<res<<endl;
    }
    cout<<res;
}