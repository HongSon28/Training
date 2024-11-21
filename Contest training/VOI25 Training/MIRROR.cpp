#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
struct dat{
	int type,d,c;
} a[N+5];
pair<int,int>qu[N+5];
int res[N+5];
namespace sub1{
	int dir=1,pos=0;
	vector<int>v[2][N+5];
	int c[2][N+5];
	bool check() {
		for (int i=1;i<=q;i++) {
			if (qu[i].first>N) return false;
		}
		return true;
	}
	void solve() {
		for (int i=1;i<=n;i++) {
			if (a[i].type==1) {
				for (int j=1;j<=a[i].c;j++) {
					if (a[i].d*j>N) break;
					c[1][a[i].d*j]++;
				}
			} else {
				for (int j=1;j<=a[i].c;j++) {
					if (a[i].d*j>N) break;
					c[0][a[i].d*j]++;
				}
			}
		}
		res[0]=0;
		for (int t=1;t<=N;t++) {
			pos+=dir;
			//cout<<pos<<' '<<dir<<endl;
			if (dir==1) {
				if (c[1][pos]) {
					c[1][pos]--;
					dir=-1;
				}
			} else {
				if (c[0][-pos]) {
					c[0][-pos]--;
					dir=1;
				}
			} 
			res[t]=pos;
		}
		for (int i=1;i<=q;i++) cout<<res[qu[i].first]<<'\n';
	}
}
int main() {
	freopen("mirror.inp","r",stdin);
	freopen("mirror.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	char ch;
    	cin>>ch>>a[i].d>>a[i].c;
    	if (ch=='R') a[i].type=1;
    	else a[i].type=-1;
    }	
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].first;
		qu[i].second=i;
	}
	if (sub1::check()) sub1::solve();
}