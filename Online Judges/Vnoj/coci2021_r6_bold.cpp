#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
char ch,c[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>ch;
			if (ch=='#') {
				c[i][j]=c[i+1][j]=c[i][j+1]=c[i+1][j+1]='#';
			}
		}
	} 
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) {
			if (c[i][j]!='#') cout<<'.';
			else cout<<c[i][j];
		}
		cout<<'\n';
	}
}