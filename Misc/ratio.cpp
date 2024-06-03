#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
double s0[N+5],s1[N+5],sum[N+5],x,y;
string s;
int res;
map<double,int>m;
signed main(){
    cin>>x>>y>>s;
    int n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            s1[i]=s1[i-1];
            s0[i]=s0[i-1]+1;
        }else{
            s0[i]=s0[i-1];
            s1[i]=s1[i-1]+1;
        }
        sum[i]=s1[i]/y-s0[i]/x;
        cout<<s1[i]<<' '<<s0[i]<<' '<<sum[i]<<endl;
    }
    for(int i=0;i<=n;i++) m[sum[i]]++;
    for(auto i=m.begin();i!=m.end();i++) {
    	res+=i->second*(i->second-1)/2;
    	cout<<i->first<<' '<<i->second<<endl;
    }
    cout<<res;
}