#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s[N+5];
long long c2[101],c4[10001];
pair<long long,int>p[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	int temp=(s[i][4]-'0')*10+s[i][5]-'0';
    	c2[temp]++;
    	temp+=(s[i][3]-'0')*100;
    	temp+=(s[i][2]-'0')*1000;
    	c4[temp]++;
    }	
    for (int i=0;i<=99;i++) p[i]={c2[i],i};
    sort(p,p+100,greater<pair<int,int>>());
    res=(p[0].first+p[1].first+p[2].first)*500;
    for (int x=0;x<=9999;x++) {
    	long long cur=c4[x]*4000;
    	int t=x%100;
    	vector<long long>temp;
    	int i=0;
    	while (temp.size()<4) {
    		if (p[i].second!=t) temp.push_back(p[i].first);
    		i++;
    	}
    	res=max(res,cur+(temp[0]+temp[1]+temp[2])*500);
    	while (!temp.empty()&&temp.back()==0) temp.pop_back();
    	if (!temp.empty()) {
    		cur+=300000;
    		temp.pop_back();
    	}	
    	long long sum=0;
    	for (auto s:temp) sum+=s;
    	cur+=sum*500;
    	res=max(res,cur);
    }
    cout<<res;
}