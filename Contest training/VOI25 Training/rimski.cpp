#include<bits/stdc++.h>
using namespace std;
int p[255];
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    for (auto i:s) p[(int)i]++;
    if (p['C']==1) {
    	cout<<"XC";
    	p['C']--;
    	p['X']--;
    }
    if(p['L']==1) {
		if(p['X']==1||(p['X']==2&&p['I']==1&&p['V']==0)){
			cout<<"X";
			p['X']--;
		}
		cout<<"L";
		p['L']--;
	}	
	while(p['X']>1) {
		cout<<"X";
		p['X']--;
	}
	if(p['X']==1&&p['V']==0&&p['I']==1) { 
		cout<<"IX"; 
		p['X']--;
		p['I']--; 
	}
	if(p['X']==1) { 
		cout<<"X"; 
		p['X']--; 
	}
	if(p['I']==1&&p['V']==1) { 
		cout<<"I";
		p['I']--; 
	}
	if(p['V']==1) { 
		cout<<"V"; 
		p['V']--; 
	}
	while(p['I']>0) { 
		cout<<"I"; 
		p['I']--; 
	}
}