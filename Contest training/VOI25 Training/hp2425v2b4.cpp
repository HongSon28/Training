#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n;
pair<long long,long long> f[N+5][10];
long long res;
int calc(long long i) {
	long long mx=0;
	while (i>0) {
		mx=max(mx,i%10);
		i/=10;
	}
	return mx;
}
void prep() {
	for (int j=0;j<=9;j++) {
		for (int i=1;i<=N;i++) {
			int t=calc(i);
			if (t>=j) f[i][j]={f[i-t][j].first+1,f[i-t][j].second+t};
			else if (j<=i) f[i][j]={f[i-j][j].first+1,f[i-j][j].second+j};
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>n;
    while (n>N) {
    	long long t=n%N;
    	int mx=calc(n-t);
    	res+=f[t][mx].first;
    	n-=f[t][mx].second;
    	n-=mx;
    	res++;
    	//cout<<n<<' '<<res<<endl;
    }
    cout<<res+f[n][0].first;
}