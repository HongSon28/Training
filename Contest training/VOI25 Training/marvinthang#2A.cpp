#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long sum1,sum2,res;
vector<long long>v[2];
long long sum[N+5];
long long get(int l,int r) {
	return sum[r]-sum[l-1];
}
long long solve(int id) {
	long long ans=1e18;
	if (v[id].size()==1) return (long long)1e18;
	sort(v[id].begin(),v[id].end());
	int n=v[id].size()-1;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+v[id][i];
	for (int i=1;i<=n;i++) {
		int len=n-i+1;
		long long mid;
		if (len%2==1) {
			int pos=i+len/2;
			mid=v[id][pos];
			ans=min(ans,get(1,i-1)+mid*(pos-i)-get(i,pos-1)+get(pos+1,n)-mid*(n-pos));
			//cout<<i<<' '<<n<<' '<<mid<<' '<<pos<<' '<<ans<<endl;
		} else {
			int pos1=i+len/2-1,pos2=i+len/2;
			mid=(v[id][pos1]+v[id][pos2])/2;
			ans=min(ans,get(1,i-1)+mid*(pos1-i+1)-get(i,pos1)+get(pos2,n)-mid*(n-pos2+1));
			//cout<<i<<' '<<n<<' '<<mid<<' '<<pos1<<' '<<pos2<<' '<<get(1,i-1)+mid*(pos1-i+1)-get(i,pos1)+get(pos2,n)-mid*(n-pos2+1)<<endl;
		}		
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    v[0].push_back(0),v[1].push_back(0);
    for (int i=1;i<=n;i++) {
    	long long t;
    	cin>>t;
    	if (t<0) {
    		sum1-=t;
    		v[0].push_back(-t);
    	}
    	else {
    		sum2+=t;
    		v[1].push_back(t);
    	}
    }
 	res=sum1+sum2;
 	res=min(res,sum1+solve(1));
 	res=min(res,sum2+solve(0));
 	cout<<res;   
}