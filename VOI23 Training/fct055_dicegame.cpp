#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[5],b[5];
double dp1[N+5],dp2[N+5],eps=1e-9;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a[1]>>b[1]>>a[2]>>b[2];
    for (int i=a[1];i<=b[1];i++) {
    	for (int j=a[2];j<=b[2];j++) {
    		dp1[i+j]+=1.0/(b[1]-a[1]+1)/(b[2]-a[2]+1);
    	}
    }
    cin>>a[3]>>b[3]>>a[4]>>b[4];
    for (int i=a[3];i<=b[3];i++) {
    	for (int j=a[4];j<=b[4];j++) {
    		dp2[i+j]+=1.0/(b[3]-a[3]+1)/(b[4]-a[4]+1);
    	}
    }
    double p1=0,p2=0;
    for (int i=0;i<=N;i++) {
    	for (int j=0;j<=N;j++) {
    		if (i>j) p1+=dp1[i]*dp2[j];
    		else if (i<j) p2+=dp1[i]*dp2[j];
    	}
    }
    if (abs(p1-p2)<eps) cout<<3;
    else if (p1>p2) cout<<1;
    else cout<<2; 
}