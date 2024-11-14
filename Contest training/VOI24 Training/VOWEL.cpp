#include<bits/stdc++.h>
using namespace std;
string s;
vector<vector<int>>adj(26);
int col[26];
bool mark[26];
vector<int>vc[5];
char vowel[5]={'A','E','I','O','U'};
vector<char>notvowel;
char c[26];
void bfs(int u) {
	for (auto v:adj[u]) {
		//cout<<u<<' '<<v<<' '<<col[u]<<' '<<col[v]<<endl;
		if (col[v]!=0&&col[v]==col[u]) {
			cout<<"impossible";
			exit(0);
		}
		if (col[v]!=0&&col[v]!=col[u]) continue;
		if (col[u]==1) col[v]=2;
		else col[v]=1;
		vc[col[v]].push_back(v);
		bfs(v);
	}
}
vector<pair<int,int>>temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	getline(cin,s);
	for (char ch='A';ch<='Z';ch++) {
		if (ch!='A'&&ch!='E'&&ch!='I'&&ch!='O'&&ch!='U') notvowel.push_back(ch);
	}
	for (int i=1;i<(int)s.size();i++) {
		if (s[i-1]!=' '&&s[i]!=' ') {
			adj[s[i-1]-'A'].push_back(s[i]-'A');
			adj[s[i]-'A'].push_back(s[i-1]-'A');
		}
	}
	for (auto j:s) {
		if (j==' ') continue;
		int i=j-'A';
		if (!col[i]) {
			//cout<<i<<endl;
			vc[1].clear();
			vc[2].clear();
			col[i]=1;
			vc[1].push_back(i);
			bfs(i);
			if (vc[1].size()>vc[2].size()) swap(vc[1],vc[2]);
			temp.push_back({vc[2].size()-vc[1].size(),i});
			for (auto t:vc[1]) vc[3].push_back(t);
			for (auto t:vc[2]) vc[4].push_back(t);
		}
	}
	if (vc[3].size()>vc[4].size()) swap(vc[3],vc[4]);
	if (vc[3].size()<5&&vc[4].size()>21) {
		int dif=5-vc[3].size();
		bool dp[dif+1]={};
		pair<int,int> trace[dif+1]={};
		dp[0]=true;
		for (auto [t,k]:temp) {
			for (int i=dif;i>=t;i--) {
				if (!dp[i]&&dp[i-t]) {
					trace[i]={t,k};
					dp[i]=true;
				}
			}
		}
		for (int i=dif;i>=0;i--) {
			if (dp[i]) {
				while (i>0) {
					pair<int,int>t=trace[i];
					mark[t.second]=true;
					i-=t.first;
				}
				memset(col,0,sizeof(col));
				vc[3].clear();
				vc[4].clear();
				for (auto j:s) {
					if (j==' ') continue;
					int p=j-'A';
					if (!col[p]) {
						vc[1].clear();
						vc[2].clear();
						col[p]=1;
						vc[1].push_back(p);
						bfs(p);
						if (vc[1].size()>vc[2].size()) swap(vc[1],vc[2]);
						if (mark[p]) swap(vc[1],vc[2]);
						for (auto t:vc[1]) vc[3].push_back(t);
						for (auto t:vc[2]) vc[4].push_back(t);
					}
				}
				break;
			}
		}
	}
	if (vc[3].size()>5||vc[4].size()>21) {
		cout<<"impossible";
		return 0;
	}
	for (int i=0;i<(int)vc[3].size();i++) c[vc[3][i]]=vowel[i];
	for (int i=0;i<(int)vc[4].size();i++) c[vc[4][i]]=notvowel[i];
	for (int i=0;i<(int)s.size();i++) {
		if (s[i]==' ') cout<<' ';
		else cout<<c[s[i]-'A'];
	}
}