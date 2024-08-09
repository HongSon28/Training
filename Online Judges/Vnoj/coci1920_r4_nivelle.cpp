#include<bits/stdc++.h>
using namespace std;
int n;
string s;
double mx=1e9;
int lo,hi;
int cur[26];
void calc(int k) {
	memset(cur,0,sizeof(cur));
	int l=1,r=1;
	cur[s[1]-'a']++;
	int cnt=1;
	while (r<n) {
		if (cnt<k) {
			r++;
			cur[s[r]-'a']++;
			if (cur[s[r]-'a']==1) cnt++;
		} else if (cnt==k&&cur[s[r+1]-'a']>0) {
			cur[s[r+1]-'a']++;
			r++;
		} else {
			if (cnt==k) {
				double temp=(double)k/(double)(r-l+1);
				if (temp<mx) {
					mx=temp;
					lo=l;
					hi=r;
				}
				//cout<<l<<' '<<r<<' '<<k<<' '<<temp<<endl;
			}
			cur[s[l]-'a']--;
			if (cur[s[l]-'a']==0) cnt--;
			l++;
		}
	}
	if (cnt==k) {
		double temp=(double)k/(double)(r-l+1);
		if (temp<mx) {
			mx=temp;
			lo=l;
			hi=r;
		}
		//cout<<l<<' '<<r<<' '<<k<<' '<<temp<<endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	for (int i=1;i<=26;i++) calc(i);
	cout<<lo<<' '<<hi;
}