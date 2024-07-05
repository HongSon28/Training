#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,cur;
string s;
map<string,int>id;
int cnt[N+5],last[N+5];
string st[N+5];
vector<int>vc;
bool comp(int x,int y){
	if (cnt[x]!=cnt[y]) return cnt[x]>cnt[y];
	return last[x]>last[y];
}
int main() {
	freopen("gratitude.inp","r",stdin);
	freopen("gratitude.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    cin.ignore();
    for (int i=1;i<=n*3;i++) {
    	getline(cin,s);
    	if (id.count(s)==0) {
    		id[s]=++cur;
    		st[id[s]]=s;
    	}
    	cnt[id[s]]++;
    	last[id[s]]=i;	
    	//cout<<s<<' '<<id[s]<<endl;
    }
    for (int i=1;i<=cur;i++) vc.push_back(i);
    sort(vc.begin(),vc.end(),comp);
    for (int i=0;i<min(k,cur);i++) cout<<st[vc[i]]<<'\n';
}