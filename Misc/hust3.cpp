#include<bits/stdc++.h>
using namespace std;
double a,b;
double x[51],y[51];
void read_data() {
	freopen("house_prices.txt","r",stdin);
	cin>>a>>b;
	for (int i=1;i<=50;i++) {
		int index;
		cin>>index;
		cin>>x[index]>>y[index];
	}
}
double calculate_error() {
	double sum=0;
	for (int i=1;i<=50;i++) {
		double pre=a*x[i]+b;
		sum+=(pre-y[i])*(pre-y[i]);
	}
	return sum*1/50;
}
int main() {
	read_data();
	cout.precision(4);
	cout<<fixed<<calculate_error();
}