#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.length();
    string np="";
    for (int i=0;i<n;i++) {
        if (s[i]=='0') {
            np+="0000";
        } else if (s[i]=='1') {
            np+="0001";
        } else if (s[i]=='2') {
            np+="0010";
        } else if (s[i]=='3') {
            np+="0011";
        } else if (s[i]=='4') {
            np+="0100";
        } else if (s[i]=='5') {
            np+="0101";
        } else if (s[i]=='6') {
            np+="0110";
        } else if (s[i]=='7') {
            np+="0111";
        } else if (s[i]=='8') {
            np+="1000";
        } else if (s[i]=='9') {
            np+="1001";
        } else if (s[i]=='A') {
            np+="1010";
        } else if (s[i]=='B') {
            np+="1011";
        } else if (s[i]=='C') {
            np+="1100";
        } else if (s[i]=='D') {
            np+="1101";
        } else if (s[i]=='E') {
            np+="1110";
        } else {
            np+="1111";
        }
    }
    while (np[0]=='0') {
        np.erase(0,1);
    }
    cout<<np;
}
