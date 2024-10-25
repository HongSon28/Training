#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
struct mat{
	int row,col;
	long long a[4][4];
};
mat mul(mat x,mat y) {
	mat ans;
	ans.row=x.row,ans.col=y.col;
	for (int i=1;i<=ans.row;i++) { 
		for (int j=1;j<=ans.col;j++) {
			ans.a[i][j]=0;
			for (int k=1;k<=x.col;k++) {
				ans.a[i][j]+=x.a[i][k]*y.a[k][j]%(mod-1);
				ans.a[i][j]%=mod-1;
			}
		}
	}
	return ans;
}
mat power(mat x,long long y) {
	if (y==1) return x;
	mat ans=power(x,y/2);
	ans=mul(ans,ans);
	if (y%2==1) ans=mul(ans,x);
	return ans;
}
long long lpow(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=lpow(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long n,f1,f2,f3,c;
set<int>s;
mat base,a;
long long res=1;
void calc(int x) {
	if (x==1||s.count(x)) return;
	s.insert(x);
	a.col=1,a.row=3;
	long long temp=f1;
	a.a[1][1]=a.a[2][1]=a.a[3][1]=0;
	while (temp%x==0) {
		temp/=x;
		a.a[3][1]++;
	}
	temp=f2;
	while (temp%x==0) {
		temp/=x;
		a.a[2][1]++;
	}
	temp=f3;
	while (temp%x==0) {
		temp/=x;
		a.a[1][1]++;
	}
	mat ans=power(base,n-3);
	ans=mul(ans,a);
	//cout<<x<<' '<<ans.a[1][1]<<' '<<lpow(x,ans.a[1][1])<<endl;
	res*=lpow(x,ans.a[1][1]);
	res%=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    base.col=base.row=3;
    base.a[1][1]=base.a[1][2]=base.a[1][3]=base.a[2][1]=base.a[3][2]=1;
    cin>>n>>f1>>f2>>f3>>c;
    f1=f1*c%mod;
    f2=f2*lpow(c,2)%mod;
    f3=f3*lpow(c,3)%mod;
    long long temp=f1;
    for (int i=2;i*i<=temp;i++) {
    	if (temp%i!=0) continue;
    	calc(i);
    	while (temp%i==0) temp/=i;
    }
    if (temp!=1) calc(temp);
    temp=f2;
    for (int i=2;i*i<=temp;i++) {
    	if (temp%i!=0) continue;
    	calc(i);
    	while (temp%i==0) temp/=i;
    }
    if (temp!=1) calc(temp);
    temp=f3;
    for (int i=2;i*i<=temp;i++) {
    	if (temp%i!=0) continue;
    	calc(i);
    	while (temp%i==0) temp/=i;
    }
    if (temp!=1) calc(temp);
    cout<<res*lpow(lpow(c,n),mod-2)%mod;
}