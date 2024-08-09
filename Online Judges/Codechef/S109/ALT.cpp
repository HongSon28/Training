#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,t;
int a[N+5],b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		bool flag=true;
		cin>>n;
		vector<int>even,odd;
		for (int i=1;i<=n;i++) cin>>b[i];
		sort(b+1,b+1+n,greater<int>());
		for (int i=1;i<=n;i++) {
			if (b[i]%2==0) even.push_back(b[i]);
			else odd.push_back(b[i]);
		}
		if (odd.size()%2!=0||even.size()%2!=0) {
			cout<<-1<<'\n';
			continue;
		}
		int pos=1;
		for (int i=0;i<odd.size()/2;i++) {
			int temp=odd[i+odd.size()/2];
			a[pos]=(odd[i]+temp)/2;
			a[pos+n/2]=(odd[i]-temp)/2;
			pos++;
		}
		for (int i=0;i<even.size()/2;i++) {
			int temp=even[i+even.size()/2];
			a[pos]=(even[i]+temp)/2;
			a[pos+n/2]=(even[i]-temp)/2;
			pos++;
		}
		for (int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
}