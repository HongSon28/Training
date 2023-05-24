#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string res;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='A') res+="F";
        else if (s[i]=='B') res+="G";
        else if (s[i]=='C') res+="H";
        else if (s[i]=='D') res+="I";
        else if (s[i]=='E') res+="J";
        else if (s[i]=='F') res+="K";
        else if (s[i]=='G') res+="L";
        else if (s[i]=='H') res+="M";
        else if (s[i]=='I') res+="N";
        else if (s[i]=='J') res+="O";
        else if (s[i]=='K') res+="P";
        else if (s[i]=='L') res+="Q";
        else if (s[i]=='M') res+="R";
        else if (s[i]=='N') res+="S";
        else if (s[i]=='O') res+="T";
        else if (s[i]=='P') res+="U";
        else if (s[i]=='Q') res+="V";
        else if (s[i]=='R') res+="W";
        else if (s[i]=='S') res+="X";
        else if (s[i]=='T') res+="Y";
        else if (s[i]=='U') res+="Z";
        else if (s[i]=='V') res+="A";
        else if (s[i]=='W') res+="B";
        else if (s[i]=='X') res+="C";
        else if (s[i]=='Y') res+="D";
        else if (s[i]=='Z') res+="E";
    }
    cout<<res;
}
