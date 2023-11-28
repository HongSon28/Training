#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int m=0;m<t;m++) {
        string s;
        cin>>s;
        int i=0;
        int ta=0,tb=0;
        while (s[i]!='+') {
            ta*=10;
            ta+=(int)s[i]-48;
            i++;
        }
        i++;
        for (int j=i;j<s.size();j++) {
            tb*=10;
            tb+=(int)s[j]-48;
        }
        cout<<ta+tb<<endl;
    }
}
