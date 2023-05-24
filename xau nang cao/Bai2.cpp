#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    string kq[t];
    for (int i=0;i<t;i++) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        for (int j=0;j<n;j++) {
            if (s[j]=='U') {
                kq[i].push_back('D');
            } else if (s[j]=='D') {
                kq[i].push_back('U');
            } else if (s[j]=='L'){
                kq[i].push_back('L');
            } else {
                kq[i].push_back('R');
            }
        }
    }
    for (int i;i<t;i++)
        cout<<kq[i]<<endl;
}
