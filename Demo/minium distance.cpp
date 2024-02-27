#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5;
int n,a[N+4],s1[N+5],s2[N+5],s3[N+5],res=1e18;
int get_left(int l,int r) {
	return (s3[r]-s3[l-1])-(s1[r]-s1[l-1])*(n*3-r);
}
int get_right(int l,int r) {
	return (s2[r]-s2[l-1])-(s1[r]-s1[l-1])*(l-1);
}
signed main(){
    cin>>n;
    int m=3*n;
    for(int i=n+1;i<=2*n;i++){
        cin>>a[i];
        a[i-n]=a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=3*n;i++){
        s1[i]=s1[i-1]+a[i];
        s2[i]=s2[i-1]+a[i]*i;
        s3[i]=s3[i-1]+a[i]*m;
        m--;
        //cout<<a[i]<<' ';
    }
    //cout<<endl;
    for(int i=n+1;i<=2*n;i++){
		if (n%2==0) {
			int l1=i-n/2+1,r1=i-1,r2=i+n/2,l2=i+1;
			res=min(res,get_left(l1,r1)+get_right(l2,r2));
			l1=i-n/2,r1=i-1,r2=i+n/2-1,l2=i+1;
			res=min(res,get_left(l1,r1)+get_right(l2,r2));
		} else {
			int l1=i-n/2,r1=i-1,r2=i+n/2,l2=i+1;
			res=min(res,get_left(l1,r1)+get_right(l2,r2));
			
		}
        //cout<<l1<<' '<<r1<<' '<<s3[r1]-s3[l1-1]<<' '<<(s1[r1]-s1[l1-1])*(n*3-r1)<<' '<<sl<<endl;
        //cout<<l2<<' '<<r2<<' '<<s2[r2]-s2[l2-1]<<' '<<(s1[r2]-s1[l2-1])*(l2-1)<<' '<<sr<<endl<<endl;
    }
    cout<<res;
}