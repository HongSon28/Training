#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
bitset<N+5>eq[N+5];
void gauss() {
    vector<int>res;
    for(int i=1;i<=n;i++) {
       int pos=0;
       for(int j=1;j<=n;j++) {
           if(eq[i][j]) {
                pos=j;
                break;
            }
        }
        for(int j=1;j<=n;j++) {
            if((i!=j)&&(eq[j][pos])) eq[j]^=eq[i];
        }
    }
    for(int i=1;i<=n;i++) {
        int pos=0;
        for(int j=1;j<=n;j++) {
            if(eq[i][j])
            {
                pos=j;
                break;
            }
        }
        if(eq[i][n+1])
            if(pos!=0) res.push_back(pos);
            else {
                cout<<-1<<'\n';
                return;
            }
    }
    if(res.empty())
    {
        cout<<-1<<'\n';
        return;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<' ';
    cout<<'\n';
}
int main() {
	int t;
	cin>>t;
	while (t--) {
	    cin>>n>>s;
	    s=' '+s;
	    for (int i=1;i<=n;i++) eq[i].reset();
	    for (int i=1;i<=n;i++) {
	        if (s[i]=='1') eq[i].set(n+1);
	    }
	    for (int i=1;i<=n;i++) {
	        int temp;
	        cin>>temp;
	        eq[temp].set(i);
	        eq[i].set(i);
	    }
	    gauss();
    }
}
