#include<bits/stdc++.h>
using namespace std;
double code,code1;
string type;
string s1="+-------------------------------------------------+";
string s2,s3,s4,s5,s6;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>code>>type;
    string cd=to_string((int)code);
    int t2=(19-cd.size())/2,t1=19-cd.size()-t2;
    string x1,x2;
    while (t1--) x1+=" ";
    while (t2--) x2+=" ";
    s2="|        Account Number       |"+x1+cd+x2+"|";
    cin>>code;
    cd=to_string((int)code);
    t2=(19-cd.size())/2,t1=19-cd.size()-t2;
    x1.clear(),x2.clear();
    while (t1--) x1+=" ";
    while (t2--) x2+=" ";
    s5="|       Premium Channels      |"+x1+cd+x2+"|";
    if (type=="r"||type=="R") {
    	s3="|        Customer Type        |    Residential    |";
    	code=25+7.5*code;
    }
    else if (type=="b"||type=="B") {
    	s3="|        Customer Type        |      Business     |";
    	code=15+50*code;
    	cin>>code1;
    	if (code1>=10) {
    		code+=75;
    		code1-=10;
    		code+=code1*5;
    	}
    }
    else {
    	cout<<"Invalid customer type.";
    	return 0;
    }
    if (floor(code)==code) cd=to_string((int)code)+".00";
    else cd=to_string((int)code)+".50";
    t2=(19-cd.size())/2,t1=19-cd.size()-t2;
    x1.clear(),x2.clear();
    while (t1--) x1+=" ";
    while (t2--) x2+=" ";
    s6="|         Total Amount        |"+x1+cd+x2+"|";
    cout<<s1<<'\n'<<s2<<'\n'<<s1<<'\n'<<s3<<'\n'<<s1<<'\n'<<s5<<'\n'<<s1<<'\n'<<s6<<'\n'<<s1;
}