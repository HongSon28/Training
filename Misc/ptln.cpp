#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,p[N+5],a[N+5],mn[N+5],res[N+5],inf=1e9;
set<int>s[N+5];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>a[i];
    	mn[i]=inf;
    }
    for(int i=2;i<=N;i++)
        if(!p[i])
            for(int j=i;j<=N;j+=i)
                if(!p[j]) p[j]=i;
    for(int i=1;i<=N;i++)
        if(!p[i]) p[i]=i;
    for(int i=1;i<=n;i++){
        int x=a[i];
        while(x!=1){
            s[p[x]].insert(i);
            x/=p[x];
        }
    }
	for(int i=1;i<=n;i++){
        int x=a[i];
        while(x!=1){
            auto it=s[p[x]].upper_bound(i);
            if (it==s[p[x]].end()) {
            	x/=p[x];
            	continue;
            }
            int j=*it;
            if (j-i<mn[j]) {
            	mn[j]=j-i;
            	res[j]=i;
            }
            if (j-i<mn[i]) {
            	mn[i]=j-i;
            	res[i]=j;
            }
            x/=p[x];
        }
    }
    for (int i=1;i<=n;i++) {
    	if (mn[i]==inf) cout<<-1<<' ';
    	else cout<<res[i]<<' ';
    }
}
