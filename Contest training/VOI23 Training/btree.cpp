#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21);
long long d,n;
long long a[N+5];
long long calc(long long l,long long r) {
	if (l==r) return 0;
	long long mid=(l+r)/2;
	long long t1=calc(l,mid),t2=calc(mid+1,r),s1=0,s2=0;
	//cout<<l<<' '<<r<<' '<<mid<<endl;
	//for (int i=l;i<=r;i++) cout<<a[i]<<' ';
	//cout<<endl;
	long long x=l,y=mid+1;
	while (x<=mid) {
		while (a[x]>a[y]&&y<=r) y++;
		s1+=y-1-mid;
		//cout<<x<<' '<<y<<' '<<s1<<endl;
		x++;
	}
	s2=(mid-l+1)*(r-mid)-s1;
	//cout<<s1<<' '<<s2<<endl<<endl;
	vector<long long>merged;
	x=l,y=mid+1;
	while (x<=mid&&y<=r) {
		if (a[x]<a[y]&&x<=mid) {
			merged.push_back(a[x]);
			x++;
		} else if (a[x]>=a[y]&&y<=r){
			merged.push_back(a[y]);
			y++;
		}
	}	
	while (x<=mid) {
		merged.push_back(a[x]);
		x++;
	}
	while (y<=r) {
		merged.push_back(a[y]);
		y++;
	}
	long long pos=l;
	for (auto t:merged) {
		a[pos]=t;
		pos++;
	}
	//cout<<endl;
	//cout<<t1<<' '<<t2<<' '<<s1<<' '<<s2<<endl<<endl;
	return t1+t2+min(s1,s2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>d;
    n=(1<<d);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    cout<<calc(1,n);
}
