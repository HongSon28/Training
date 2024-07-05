#include<bits/stdc++.h>
using namespace std;
int a[4][5],b[4][5],k,t;
void r1() {
	b[1][1]=a[2][1];
	b[1][2]=a[1][1];
	b[1][3]=a[1][2];
	b[2][1]=a[3][1];
	b[2][2]=a[2][2];
	b[2][3]=a[1][3];
	b[3][1]=a[3][2];
	b[3][2]=a[3][3];
	b[3][3]=a[2][3];
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			a[i][j]=b[i][j];
}
void r2() {
	b[1][2]=a[1][3];
	b[1][3]=a[1][4];
	b[1][4]=a[2][4];
	b[2][2]=a[1][2];
	b[2][3]=a[2][3];
	b[2][4]=a[3][4];
	b[3][2]=a[2][2];
	b[3][3]=a[3][2];
	b[3][4]=a[3][3];
	for (int i=1;i<=3;i++)
		for (int j=2;j<=4;j++)
			a[i][j]=b[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    for (int i=1;i<=3;i++)
    	for (int j=1;j<=4;j++) 
    		cin>>a[i][j];
    cin>>k;
    while (k--) {
    	cin>>t;
    	if (t==1) r1();
    	else r2();
    }
    for (int i=1;i<=3;i++) {
    	for (int j=1;j<=4;j++) {
    		cout<<a[i][j]<<' ';
    	}
    	cout<<'\n';
    }
}