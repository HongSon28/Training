#include<bits/stdc++.h>
using namespace std;
int n,m,res;
int a[15005][1505];
vector<int>v[15005];
int cur[15005];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    //freopen("maxreg.inp","r",stdin);
    //freopen("maxreg.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    for (int j=1;j<=m;j++) {
    	int last=1;
    	for (int i=2;i<=n+1;i++) {
    		if (a[i][j]!=a[last][j]) {
    			if (a[last][j]) v[last].push_back(i-1);
    			last=i;
    		}
    	}
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
    	cnt-=cur[i-1];
        for (auto x:v[i]) {
        	cnt++;
        	cur[x]++;
        }
        //for (int j=1;j<=n;j++) cout<<cur[j]<<' ';
        //cout<<endl;
        int temp=cnt;
        for (int j=i;j<=n;j++) {
        	if (i!=j) temp-=cur[j-1];
        	res=max(res,temp*(j-i+1));
        }
    }
    cout<<res;
}
