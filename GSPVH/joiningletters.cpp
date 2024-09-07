#include<bits/stdc++.h>
using namespace std;
string s;
long long c[4];
int main() {
	freopen("joiningletters.inp","r",stdin);
	freopen("joiningletters.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (cin>>s) {
    	if (s=="$") return 0;
    	c[0]=c[1]=c[2]=c[3]=0;
    	long long l1=0,l2=0;
    	for (int i=0;i<s.size();i++) {
    		if (s[i]=='I') c[0]++;
    		else if (s[i]=='C') {
    			if (i>=1&&s[i-1]=='I') {
    				c[1]+=c[0]-1;
    				l1=c[0]-1;
    			} else {
    				c[1]+=c[0];
    				l1=c[0];
    			}
    			if (i>=1&&s[i-1]=='P') c[3]+=c[2]-l2;
    			else c[3]+=c[2];
    		} else if (s[i]=='P') {
    			if (i>=1&&s[i-1]=='C') {
    				c[2]+=c[1]-l1;
    				l2=c[1]-l1;
    			} else {
    				c[2]+=c[1];
    				l2=c[1];
    			}
    		}
    		//cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<' '<<c[3]<<endl;
    	}
    	cout<<c[3]<<'\n';
    }
}