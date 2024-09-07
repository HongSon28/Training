#include<bits/stdc++.h>
using namespace std;
const int N=40;
bool p[N+5];
int n;
int a[N+5];
vector<vector<int>>v;
bool used[N+5];
int res;
void rec(int k) {
	if (k==n+1) {
		if (p[a[n]+a[n+1]]) {
			res++;
			if (res<=10000) {
				vector<int>t;
				for (int i=1;i<=n;i++) t.push_back(a[i]);
				v.push_back(t);
			}
		}
		return;
	}
	for (int i=2;i<=n;i++) {
		if (!used[i]&&p[i+a[k-1]]) {
			used[i]=true;
			a[k]=i;
			rec(k+1);
			used[i]=false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=true;
    cin>>n;
    n*=2;
    a[1]=a[n+1]=1;
    rec(2);
    cout<<res<<'\n';
    for (auto vc:v) {
    	for (auto x:vc) cout<<x<<' ';
    	cout<<'\n';
    }
}