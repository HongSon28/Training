#include<bits/stdc++.h>
using namespace std;
int n;
int col[405][405];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		col[x+200][y+200]=z;
	}
	for (int i=0;i<=400;i++) {
		for (int j=i+1;j<=400;j++) {
			long long c12=0,c23=0,c34=0,c14=0,c13=0,c24=0;
			for (int k=0;k<=400;k++) {
				c12+=(col[i][k]==1&&col[j][k]==2)||(col[i][k]==2&&col[j][k]==1);
				c23+=(col[i][k]==2&&col[j][k]==3)||(col[i][k]==3&&col[j][k]==2);
				c34+=(col[i][k]==3&&col[j][k]==4)||(col[i][k]==4&&col[j][k]==3);
				c14+=(col[i][k]==1&&col[j][k]==4)||(col[i][k]==4&&col[j][k]==1);
				c13+=(col[i][k]==1&&col[j][k]==3)||(col[i][k]==3&&col[j][k]==1);
				c24+=(col[i][k]==2&&col[j][k]==4)||(col[i][k]==4&&col[j][k]==2);
			}
			res+=c12*c34+c23*c14+c13*c24;
		}
	}
	cout<<res;
}