#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,m,p[6];
long long mod,dp[N+1][11][11][11][11][11];
int main() {
	cin>>n>>k>>m>>mod;
	for (int i=1;i<=m;i++) cin>>p[i];
	for (int i=1;i<=n;i++) {
		for (int v=0;v<k;v++) {
			for (int s1=0;s1<=10;s1++) {
				if (i>=p[1]&&i<=p[1]+9&&s1) 
				for (int s2=0;s2<=10;s2++) {
					for (int s3=0;s3<=10;s3++) {
						for (int s4=0;s4<=10;s4++) {
							for (int s5=0;s5<=10;s5++) {
							}
						}
					}
				}
			}
		}
	}
}