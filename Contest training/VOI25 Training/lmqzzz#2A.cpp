#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,k;
long long a[N+5][N+5];
long long last[N+5][N+5],cur[N+5][N+5];
vector<int>v;
void calc(int sz,int lst) {
	if (sz==1) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=i;j++) cur[i][j]=a[i][j];
		}
	} else if (sz==2) {
		for (int i=1;i<n;i++) {
			for (int j=1;j<=i;j++) cur[i][j]=max({a[i][j],a[i+1][j],a[i+1][j+1]});
		}
	} else {
		for (int i=1;i<=n;i++)
			for (int j=1;j<=i;j++) last[i][j]=cur[i][j];
		for (int i=1;i+sz-1<=n;i++) {
			for (int j=1;j<=i;j++) {
				cur[i][j]=max({last[i][j],last[i+sz-lst][j],last[i+sz-lst][j+sz-lst]});
			}
		}
	}
}
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			cin>>a[i][j];
	v.push_back(k);
	while (v.back()>=3) v.push_back((v.back()*2+2)/3);
	reverse(v.begin(),v.end());
	int lst=0;
	for (auto i:v) {
		calc(i,lst);
		lst=i;
	}
	for (int i=1;i+k-1<=n;i++) 
		for (int j=1;j<=i;j++)
			res+=cur[i][j];
	cout<<res;
}