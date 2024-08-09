#include<bits/stdc++.h>
using namespace std;
long long n,res;
string bit;
set<string>s;
long long conv(string s) {
    long long j=1,t=0;
    for (int i=s.size()-1;i>=0;i--) {
        t+=(s[i]-'0')*j;
        j*=2;
    }
    //cout<<s<<' '<<t<<endl;
    return t;
}
int main() {
    cin>>n;
    while (n!=0) {
        bit=to_string(n%2)+bit;
        n/=2;
    }
    for (int len=1;len<=bit.size();len++) {
        for (int i=0;i<bit.size()-len+1;i++) {
            string temp=bit.substr(i,len);
            while (temp[0]=='0') temp.erase(0,1);
            if (temp.empty()) temp="0";
            s.insert(temp);
        }
    }
    for (auto i:s)
        res+=conv(i);
    cout<<res;
}
