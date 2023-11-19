#include<bits/stdc++.h>
using namespace std;
int m,n;
int calc(int k) {
	return 2*(m+n)*k - 4*k -4*(k-1)*k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>m>>n;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			int lev=min({i,j,m-i+1,n-j+1});
			int temp=calc(lev-1);
			int fi=m-lev+1;
            if (j==lev) cout<<fi-i+temp+1<<' ';
            else {
                temp+=m-2*(lev-1)-1;
                if (i==lev) cout<<temp+j-lev+1<<' ';
                else {
                    int fj=n-lev+1;
                    temp+=fj-lev;
                    if (j==fj) cout<<temp+i-lev+1<<' ';
                    else {
                        temp+=m-2*(lev-1)-1;
                        cout<<temp+fj-j+1<<' ';
                    }
                }
            }
		}
		cout<<'\n';
	}
}