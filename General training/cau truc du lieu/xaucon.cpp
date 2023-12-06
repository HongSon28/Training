#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("xaucon.inp");
    ofstream out("xaucon.out");
    string s;
    inp>>s;
    set <string> a;
    int n=s.length();
    for (int l=1;l<=n;l++) {
        for (int i=0;i<n-l+1;i++) {
            string temp=s.substr(i,l);
            a.insert(temp);
        }
    }
    out<<a.size();
}
