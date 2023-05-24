#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("DECODE.INP","r",stdin);
    freopen("DECODE.OUT","w",stdout);
    string s;
    cin>>s;
    if (s.size()%2==1) {
        vector<char>left,right;
        for (int i=1;i<s.size();i++) {
            if (i%2==1)
                left.push_back(s[i]);
            else
                right.push_back(s[i]);
        }
        for (int i=left.size()-1;i>=0;i--) cout<<left[i];
        cout<<s[0];
        for (int i=0;i<right.size();i++) cout<<right[i];
    } else {
        vector<char>left,right;
        for (int i=1;i<s.size();i++) {
            if (i%2==1)
                right.push_back(s[i]);
            else
                left.push_back(s[i]);
        }
        for (int i=left.size()-1;i>=0;i--) cout<<left[i];
        cout<<s[0];
        for (int i=0;i<right.size();i++) cout<<right[i];
    }
}
