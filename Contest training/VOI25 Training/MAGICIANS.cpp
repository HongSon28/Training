#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=3e5;
int n,m;
long long a[N+5];
int l[5],r[5];
long long dp[N+5][3][3][3][3],inf=1e18,res=inf;
void mini(long long &x,const long long &y) {
	if (x>y) x=y;
}
long long calc(int i,int m1,int m2,int m3,int m4) {
	if (m1==1) return 0;
	if (m2==1) return a[i];
	if (m3==1) return a[i]*2;
	if (m4==1) return a[i]*3;
	return a[i]*m;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for (int i=1;i<=n;i++)
    	for (int m1=0;m1<3;m1++)
    		for (int m2=0;m2<3;m2++)
    			for (int m3=0;m3<3;m3++)
    				for (int m4=0;m4<3;m4++)
    					dp[i][m1][m2][m3][m4]=inf;
	for (int i=1;i<=n;i++) {
		for (int m1=0;m1<3;m1++) {
			if (m1==1&&(i>r[1]||i<l[1])) continue;
			for (int m2=0;m2<3;m2++) {
				if (m2==1&&(i>r[2]||i<l[2])) continue;
				if (m2==2&&m<2) continue;
				for (int m3=0;m3<3;m3++) {
					if (m3==1&&(i>r[3]||i<l[3])) continue;
					if (m3==2&&m<3) continue;
					for (int m4=0;m4<3;m4++) {
						if (m4==1&&(i>r[4]||i<l[4])) continue;
						if (m4==2&&m<4) continue;
						for (int n1=0;n1<=m1;n1++) 
							for (int n2=0;n2<=m2;n2++) 
								for (int n3=0;n3<=m3;n3++)
									for (int n4=0;n4<=m4;n4++)
										mini(dp[i][m1][m2][m3][m4],dp[i-1][n1][n2][n3][n4]+calc(i,m1,m2,m3,m4));
						if (i==n) mini(res,dp[i][m1][m2][m3][m4]);
						//cout<<i<<' '<<m1<<' '<<m2<<' '<<m3<<' '<<m4<<' '<<dp[i][m1][m2][m3][m4]<<endl;
					}
				}
			}
		}
	}
	cout<<res;
}