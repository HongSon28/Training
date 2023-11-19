#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int res;
int calc(char c1, char c2, char c3) {
    int phase=1,ans=0;
    for (int i=1;i<=n;i++) {
        if (phase==1) {
            if (s[i]==c1) {
                ans++;
                phase=2;
            }
        } else if (phase==2) {
            if (s[i]==c2) {
                ans++;
                phase=3;
            }
        } else {
            if (s[i]==c3) {
                ans++;
                phase=1;
            }
        }
    }
    return ans;
}
int main() {
    cin>>s;
    n=s.size();
    s=' '+s;
    cout<<max({calc('W','R','Y'),calc('W','Y','R'),calc('R','W','Y'),calc('R','Y','W'),calc('Y','R','W'),calc('Y','W','R')});
}
