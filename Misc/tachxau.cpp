#include<bits/stdc++.h>
using namespace std;
string s,n;
int f[1005],tr[1005];
vector<string>v;
vector<int>res;
void trace(int x){
    if(x==0) return;
    res.push_back(tr[x]);
	trace(x-v[tr[x]].size());
}
int main(){
    cin>>s;
    v.push_back("0");
    while(cin>>n){
        if(n=="#") break;
        v.push_back(n);
    }
    int x=s.size(),y=v.size()-1;
    s=' '+s;
    fill(f+1,f+1005,1e9);
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            int len=v[j].size();
            if(i>=len && s.substr(i-len+1,len)==v[j]) {
            	if (f[i]>f[i-v[j].size()]+1) {
	            	f[i]=f[i-v[j].size()]+1;
	            	tr[i]=j;
            	}
        	}
        }
    }
    if(f[x]!=1e9){
        cout<<f[x]<<'\n';
        trace(x);
        reverse(res.begin(),res.end());
        for (auto i:res) cout<<i<<' ';
    }
    else cout<<0;
}