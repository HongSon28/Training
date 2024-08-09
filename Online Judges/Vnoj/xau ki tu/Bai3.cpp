#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int n=s.length();
    long long thapphan=0;
    int dem=0;
    for (int i=n-1;i>=0;i--) {
        if (s[i]>='0'&&s[i]<='9') {
            thapphan=thapphan+(s[i]-48)*pow(16,dem);
        } else if (s[i]=='A') {
            thapphan=thapphan+10*pow(16,dem);
        } else if (s[i]=='B') {
            thapphan=thapphan+11*pow(16,dem);
        } else if (s[i]=='C') {
            thapphan=thapphan+12*pow(16,dem);
        } else if (s[i]=='D') {
            thapphan=thapphan+13*pow(16,dem);
        } else if (s[i]=='E') {
            thapphan=thapphan+14*pow(16,dem);
        } else {
            thapphan=thapphan+15*pow(16,dem);
        }
        dem+=1;
        s.erase(i,1);
    }
    cout<<thapphan;
}
