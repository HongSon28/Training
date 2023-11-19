#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			double temp=(double)(i*i+j*j)/2;
			double x1=sqrt(temp);
			temp=1/(double)i+1/(double)j;
			double x2=2/temp;
			if (x1<=x2) {
				cout<<i<<' '<<j<<endl;
			}
		}
	}
}