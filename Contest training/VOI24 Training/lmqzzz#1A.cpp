#include<iostream>
#include<vector>
using namespace std;
int t;
vector<long long>prime;
long long a,b,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	for (int tt=1;tt<=t;tt++) {
		cin>>a>>b>>n;
		prime.clear();
		long long res=b-a+1;
		for (long long i=2;i*i<=n;i++) {
			if (n%i==0) {
				prime.push_back(i);
				while (n%i==0) n/=i;
			}
		}
		if (n!=1) prime.push_back(n);
		int m=prime.size();
		for (int i=1;i<(1<<m);i++) {
			long long cur=1,cnt=0;
			for (int j=0;j<m;j++) 
				if (i>>j&1) {
					cur*=prime[j];
					cnt++;
				}
			if (cnt%2==1) res-=b/cur-(a-1)/cur;
			else res+=b/cur-(a-1)/cur;
		}
		cout<<"Case #"<<tt<<": "<<res<<'\n';
	}
}	