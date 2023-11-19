#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
string s;
int main() {
    cin>>n>>s;
    s=' '+s;
    for (char c='a';c<='z';c++) {
        int c[27]={};
        for (int i=1;i<=n;i++) {
            c[s[i]-'a']++;

        }
    }
}
