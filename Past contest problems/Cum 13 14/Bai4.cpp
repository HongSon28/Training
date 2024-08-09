#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int res=0,j=0;
    for (int i=s.size()-1;i>=0;i--) {
        if (s[i]=='1') {
            res+=pow(2,j);
        }
        j++;
    }
    cout<<res;
}
