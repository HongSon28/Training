#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int i=0;
    while (i<s.size()-1) {
        while (s[i]=='/'&&s[i+1]=='/') s.erase(i,1);
        i++;
    }
    while (s[s.size()-1]=='/') s.erase(s.size()-1,1);
    if (s[0]!='/') s.insert(0,"/");
    cout<<s;
}
