#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    int m1=0,m2=0;
    for (int i=0;i<n;i++) {
        cin>>s;
        while (s[0]=='0') s.erase(0,1);
        int t=s.size();
        m2=max(m2,t);
        t=stoi(s);
        m1=max(m1,t);
    }
    cout<<m1<<endl;
    for (int i=0;i<m2;i++) cout<<'9';
}
