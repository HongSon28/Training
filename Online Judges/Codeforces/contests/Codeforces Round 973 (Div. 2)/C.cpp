#include<bits/stdc++.h>
using namespace std;
int t,n,resp;
bool ask(string s) {
	cout<<"? "<<s<<endl;
	cout.flush();
	cin>>resp;
	return resp;
}
void solve(string s,bool aft) {
    //cout<<"CUR: "<<s<<endl;
	if (s.size()==n) {
		cout<<"! "<<s<<endl;
		cout.flush();
		return;
	}
	if (aft) {
        if (ask(s+"0")) solve(s+"0",1);
        else if (ask(s+"1")) solve(s+"1",1);
        else if (ask("0"+s)) solve("0"+s,0);
        else solve("1"+s,0);
	} else {
	    if (ask("0"+s)) solve("0"+s,0);
        else solve("1"+s,0);
	}
}
int main() {
	cin>>t;
	while (t--) {
		cin>>n;
		if (n==1) {
			if (ask("0")) cout<<"! 0"<<endl;
			else cout<<"! 1"<<endl;
			cout.flush();
			continue;
		}
		if (ask("00")) solve("00",1);
		else if (ask("01")) solve("01",1);
		else if (ask("11")) solve("11",1);
		else solve("10",1);
	}
}
