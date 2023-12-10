#include<bits/stdc++.h>
using namespace std;
long long l,r,res;
long long calc(long long x) {
	long long fi=((l+x-1)/x)*x;
	long long se=(r/x)*x;
	//cout<<x<<' '<<fi<<' '<<se<<' '<<(se-fi)/x+1<<endl;
	return (se-fi)/x+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>l>>r;
    for (long long i=1;i<=60;i++) res+=(calc((1ll<<i)));
    cout<<res;
}