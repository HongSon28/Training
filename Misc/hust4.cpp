#include<bits/stdc++.h>
using namespace std;
int t,c1,c2;
double a[5][253];
double mx;
double d[253];
double calc(int c1,int c2) {
	double sum=0;
	for (int i=1;i<=t;i++) {
		d[i]=(a[c1][i]+a[c2][i])/2;
		sum+=d[i];
	}
	d[0]=sum/t;
	double devi=0;
	for (int i=1;i<=t;i++) {
		devi+=(d[i]-d[0])*(d[i]-d[0]);
	}
	devi/=double(t-1);
	devi=sqrt(devi);
	return d[0]/devi;
}
int main() {
	freopen("stock_data.txt","r",stdin);
	cin>>t;
	for (int i=1;i<=t;i++) cin>>a[1][i]>>a[2][i]>>a[3][i]>>a[4][i];
	for (int i=1;i<4;i++) {
		for (int j=i+1;j<=4;j++) {
			double temp=calc(i,j);
			if (temp>mx) {
				c1=i,c2=j;
				mx=temp;
			}
		}
	}
	cout<<"Best combination of two stocks: Company ";
	if (c1==1) cout<<"A";
	else if (c1==2) cout<<"B";
	else if (c1==3) cout<<"C";
	else cout<<"D";
	cout<<" and Company ";
	if (c2==1) cout<<"A";
	else if (c2==2) cout<<"B";
	else if (c2==3) cout<<"C";
	else cout<<"D";
	cout<<endl;
	cout.precision(4);
	cout<<fixed<<"Sharpe Ratio: "<<mx;
}