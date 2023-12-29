#include<bits/stdc++.h>
using namespace std;
map<string,char>mp;
void prep() {
	char cx=92,cy=47;
	string x,y;
	x+=cx,y+=cy;
	mp["4"]='a';
	mp["8"]='b';
	mp["("]='c';
	mp["1)"]='d';
	mp["3"]='e';
	mp["1="]='f';
	mp["6"]='g';
	mp["1-1"]='h';
	mp["|"]='i';
	mp["_1"]='j';
	mp["1<"]='k';
	mp["1_"]='l';
	mp["1"+x+y+"1"]='m';
	mp["1"+x+"1"]='n';
	mp["0"]='o';
	mp["1>"]='p';
	mp["("+x+")"]='q';
	mp["12"]='r';
	mp["5"]='s';
	mp["7"]='t';
	mp["!_!"]='u';
	mp[x+y]='v';
	mp["1"+y+x+"1"]='w';
	mp["><"]='x';
	mp["9"]='y';
	mp["2"]='z';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	prep();
	string s;
	while (getline(cin,s)) {
		string res;
		int n=s.size(),i=0;
		while (i<n) {
			string t;
			if (i+3<n) {
				t=s.substr(i,4);
				if (mp.count(t)) {
					res+=mp[t];
					i+=4;
					continue;
				}
			}
			if (i+2<n) {
				t=s.substr(i,3);
				if (mp.count(t)) {
					res+=mp[t];
					i+=3;
					continue;
				}
			}
			if (i+1<n) {
				t=s.substr(i,2);
				if (mp.count(t)!=0) {
					res+=mp[t];
					i+=2;
					continue;
				}
			}
			t=s.substr(i,1);
			if (mp.count(t)!=0) {
				res+=mp[t];
				i++;
				continue;
			}
			res+=s[i];
			i++;
		}
		cout<<res<<'\n';
	}
}