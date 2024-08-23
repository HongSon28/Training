#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n;
pair<long long,long long>p[N+5];
long long cnt[N+5][N+5];
int over[N+5];
long long res[N+5];
bool check(int a,int b,int c) {
	pair<long long,long long>x={p[b].first-p[a].first,p[b].second-p[a].second},
							 y={p[c].first-p[b].first,p[c].second-p[b].second};
	long long temp=x.first*y.second-x.second*y.first;
	return (temp>0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		if (p[i].first==p[j].first&&p[j].second<p[i].second) {
    			over[i]=j;
    			break;
    		}
    	}
    }
    for (int i=1;i<n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		for (int k=1;k<=n;k++) {
    			if (i==k||j==k||p[k].first<p[i].first||p[k].first>p[j].first) continue;
    			cnt[i][j]+=check(i,k,j);
    		}
    		//cout<<i<<' '<<j<<' '<<cnt[i][j]<<endl;
    	}
    }
    for (int i=1;i<n;i++) {
    	for (int j=i+1;j<=n;j++) {
    		for (int k=i+1;k<j;k++) {
    			int cur;
    			if (check(i,k,j)) {
    				cur=cnt[i][j]-cnt[i][k]-cnt[k][j]-1;
    				if (over[k]!=0) cur++;
    			}else {
    				cur=cnt[i][k]+cnt[k][j]-cnt[i][j];
    				if (over[k]!=0) cur--;
    			}
    			
    			res[cur]++;
    			//cout<<i<<' '<<j<<' '<<k<<' '<<cur<<endl;
    		}
    	}
    }
    for (int i=1;i<=n-2;i++) cout<<res[i-1]<<'\n';
}